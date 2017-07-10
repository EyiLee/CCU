#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define FIFO 0
#define LRU 1
#define LFU 2
#define MRU 3


int ihtod(char *); // Hex string transform to Dec integer

int main (int argc ,char **argv) {
    if(argc != 6) {
        fprintf(stderr ,"command error!\n");
        return 0;
    }

    int cache_size = atoi(argv[1]);
    switch(cache_size) {
    	case 2:
        case 8:
        case 16:
        case 32:
        case 64:
        case 128:
        case 256:
            break;
        default:
            fprintf(stderr ,"command error!\n");
            return 0;
    }
    cache_size *= 1024;

    int block_size = atoi(argv[2]);
    switch(block_size) {
        case 4:
        case 8:
        case 16:
        case 32:
        case 64:
        case 128:
            break;
        default:
            fprintf(stderr ,"command error!\n");
            return 0;
    }

    int block_num = cache_size / block_size;
    int valid[block_num];
    int dirty[block_num];
    int cache_tag[block_num];
    memset(valid ,0 ,sizeof(valid));
    memset(dirty ,0 ,sizeof(dirty));
    memset(cache_tag ,0 ,sizeof(cache_tag));

    int set_size ,set_num;
    char *associativity = strdup(argv[3]);
    switch(*associativity) {
        case '1':
            set_size = 1; break;
        case '2':
            set_size = 2; break;
        case '4':
            set_size = 4; break;
        case '8':
            set_size = 8; break;
        case 'f':
        case 'F':
            set_size = block_num; break;
        default:
            fprintf(stderr ,"command error!\n");
            return 0;
    }
    set_num = block_num / set_size;

    char *replace_policy = strdup(argv[4]);
    int replace_method;
    if(strcmp(replace_policy ,"FIFO") == 0) {
        replace_method = FIFO;
    } else if(strcmp(replace_policy ,"LRU") == 0) {
        replace_method = LRU;
    } else if(strcmp(replace_policy ,"LFU") == 0) {
        replace_method = LFU;
    } else if(strcmp(replace_policy ,"MRU") == 0) {
        replace_method = MRU;
    } else {
        fprintf(stderr ,"command error!\n");
        return 0;
    }

    char *file = strdup(argv[5]);
    FILE *fp = fopen(file ,"r");
    if(fp == NULL) {
        perror("Error opening file");
    }

    /* FIFO */
    int FIFO_ptr[set_num];
    memset(FIFO_ptr ,0 ,sizeof(FIFO_ptr));

    /* LRU */
    int LRU_ptr ,LRU_lg;
    int LRU_rec[block_num];
    memset(LRU_rec ,0 ,sizeof(LRU_rec));

    /* LFU */
    int LFU_ptr ,LFU_lg ,LFU_sm;
    int LFU_fre[block_num];
    int LFU_rec[block_num];
    memset(LFU_fre ,0 ,sizeof(LFU_fre));
    memset(LFU_rec ,0 ,sizeof(LFU_rec));

    int fetch = 0;
    int hit = 0 ,miss = 0;
    int data_read = 0 ,data_write = 0;
    int Bfrom = 0 ,Bto = 0;
    
    /* Read each label */
    int i;
    char line[12];
    while(fgets(line ,12 ,fp) != NULL) {
        ++fetch;

        int label;
        char hexaddr[10];
        sscanf(line ,"%d %s" ,&label ,hexaddr);
        int addr = ihtod(hexaddr);
        int block_addr = addr / block_size;
        int index = block_addr % set_num;
        int tag = block_addr / set_num;

        int hit_ptr = false;
        int set_ptr = (block_num == set_size) ? 0 : index * set_size;
        switch(replace_method) {
            case FIFO: {
                for(i = 0 ;i < set_size ;++i) {
                    if(tag == cache_tag[set_ptr + i]) {
                        hit_ptr = true;
                        ++hit;
                        if(label == 1) {
                            dirty[set_ptr + i] = true;
                        }
                        break;
                    } else if(valid[set_ptr + i] == false) {
                        hit_ptr = true;
                        valid[set_ptr + i] = true;
                        cache_tag[set_ptr + i] = tag;
                        ++miss;
                        if(label == 1) {
                            dirty[set_ptr + i] = true;
                        }
                        break;
                    }
                }
                
                if(hit_ptr == false) {
                    cache_tag[set_ptr + FIFO_ptr[index]] = tag;
                    
                    if(dirty[set_ptr + FIFO_ptr[index]] == true) {                        
                        ++Bto;
                    }
                    
                    if(label == 1) {
                        dirty[set_ptr + FIFO_ptr[index]] = true;
                    } else {
                        dirty[set_ptr + FIFO_ptr[index]] = false;
                    }
                    
                    FIFO_ptr[index] = (FIFO_ptr[index] + 1) % set_size;
                    ++miss;
                }
                
                break;
            }
            case LRU: {
                for(i = 0 ;i < set_size ;++i) {
                    if(tag == cache_tag[set_ptr + i]) {
                        hit_ptr = true;
                        LRU_rec[set_ptr + i] = 0;
                        ++hit;
                        if(label == 1) {
                            dirty[set_ptr + i] = true;
                        }
                        break;
                    } else if(valid[set_ptr + i] == false) {
                        hit_ptr = true;
                        valid[set_ptr + i] = true;
                        cache_tag[set_ptr + i] = tag;
                        LRU_rec[set_ptr + i] = 0;
                        ++miss;
                        if(label == 1) {
                            dirty[set_ptr + i] = true;
                        }
                        break;
                    }
                }
                
                if(hit_ptr == false) {
                    LRU_lg = LRU_rec[set_ptr];
                    LRU_ptr = set_ptr;
                    for(i = 1 ;i < set_size ;++i) {
                        if(LRU_rec[set_ptr + i] > LRU_lg && valid[set_ptr + i] == true) {
                            LRU_lg = LRU_rec[set_ptr + i];
                            LRU_ptr = set_ptr + i;
                        }
                    }
                    
                    cache_tag[LRU_ptr] = tag;
                    LRU_rec[LRU_ptr] = 0;
                    
                    if(dirty[LRU_ptr] == true) {                        
                        ++Bto;
                    }
                    
                    if(label == 1) {
                        dirty[LRU_ptr] = true;
                    } else {
                        dirty[LRU_ptr] = false;
                    }
                    
                    for(i = 0 ;i < set_size ;++i) {
                        if(set_ptr + i != LRU_ptr) {
                            ++LRU_rec[set_ptr + i];
                        }
                    }
                    
                    ++miss;
                }
                
				if(hit_ptr == true) {
					for(i = 0 ;i < set_size ;++i) {
                        if(set_ptr + i != LRU_ptr) {
                            ++LRU_rec[set_ptr + i];
                        }
                    }
				}

                break;
            }
            case MRU: {
                for(i = 0 ;i < set_size ;++i) {
                    if(tag == cache_tag[set_ptr + i]) {
                        hit_ptr = true;
                        LRU_rec[set_ptr + i] = 0;
                        ++hit;
                        if(label == 1) {
                            dirty[set_ptr + i] = true;
                        }
                        break;
                    } else if(valid[set_ptr + i] == false) {
                        hit_ptr = true;
                        valid[set_ptr + i] = true;
                        cache_tag[set_ptr + i] = tag;
                        LRU_rec[set_ptr + i] = 0;
                        ++miss;
                        if(label == 1) {
                            dirty[set_ptr + i] = true;
                        }
                        break;
                    }
                }
                
                if(hit_ptr == false) {
                    LRU_lg = LRU_rec[set_ptr];
                    LRU_ptr = set_ptr;
                    for(i = 1 ;i < set_size ;++i) {
                        if(LRU_rec[set_ptr + i] < LRU_lg && valid[set_ptr + i] == true  ) {
                            LRU_lg = LRU_rec[set_ptr + i];
                            LRU_ptr = set_ptr + i;
                        }
                    }
                    
                    cache_tag[LRU_ptr] = tag;
                    LRU_rec[LRU_ptr] = 0;
                    
                    if(dirty[LRU_ptr] == true) {                        
                        ++Bto;
                    }
                    
                    if(label == 1) {
                        dirty[LRU_ptr] = true;
                    } else {
                        dirty[LRU_ptr] = false;
                    }
                    
                    // for(i = 0 ;i < set_size ;++i) {
                        // if(set_ptr + i != LRU_ptr) {
                            // ++LRU_rec[set_ptr + i];
                        // }
                    // }
                    
                    ++miss;
                }
                
				// if(hit_ptr == true) {
					for(i = 0 ;i < set_size ;++i) {
                        // if(set_ptr + i != LRU_ptr) {
                            ++LRU_rec[set_ptr + i];
                        // }
                    }
				// }

                break;
            }
            case LFU: {
                for(i = 0 ;i < set_size ;++i) {
                    if(tag == cache_tag[set_ptr + i]) {
                        hit_ptr = true;
                        ++LFU_fre[set_ptr + i];
                        LFU_rec[set_ptr + i] = 0;
                        ++hit;
                        if(label == 1) {
                            dirty[set_ptr + i] = true;
                        }
                        break;
                    } else if(valid[set_ptr + i] == false) {
                        hit_ptr = true;
                        valid[set_ptr + i] = true;
                        cache_tag[set_ptr + i] = tag;
                        LFU_fre[set_ptr + i] = 1;
                        LFU_rec[set_ptr + i] = 0;
                        ++miss;
                        if(label == 1) {
                            dirty[set_ptr + i] = true;
                        }
                        break;
                    }
                }
                
                if(hit_ptr == false) {
                    LFU_lg = LFU_rec[set_ptr];
                    LFU_sm = LFU_fre[set_ptr];
                    LFU_ptr = set_ptr;
                    for(i = 1 ;i < set_size ;++i) {
                        if(LFU_fre[set_ptr + i] < LFU_sm && valid[set_ptr + i] == true) {
                            LFU_lg = LFU_rec[set_ptr + i];
                            LFU_sm = LFU_fre[set_ptr + i];
                            LFU_ptr = set_ptr + i;
                        }
                    }
                    
                    for(i = 0 ;i < set_size ;++i) {
                        if(LFU_fre[set_ptr + i] == LFU_sm) {
                            if(LFU_rec[set_ptr + i] > LFU_lg && valid[set_ptr + i] == true) {
                                LFU_lg = LFU_rec[set_ptr + i];
                                LFU_ptr = set_ptr + i;
                            }
                            
                        }
                    }
                    
                    cache_tag[LFU_ptr] = tag;
                    LFU_fre[LFU_ptr] = 1;
                    LFU_rec[LFU_ptr] = 0;
                    
                    if(dirty[LFU_ptr] == true) {                        
                        ++Bto;
                    }
                    
                    if(label == 1) {
                        dirty[LFU_ptr] = true;
                    } else {
                        dirty[LFU_ptr] = false;
                    }
                    
                    // for(i = 0 ;i < set_size ;++i) {
                        // if(set_ptr + i != LFU_ptr) {
                            // ++LFU_rec[set_ptr + i];
                        // }
                    // }
                    
                    ++miss;
                }

                // if(hit_ptr == true) {
					for(i = 0 ;i < set_size ;++i) {
                        // if(set_ptr + i != LRU_ptr) {
                            ++LFU_rec[set_ptr + i];
                        // }
                    }
				// }

                break;
            }
        }
        
        switch(label) {
            case 0:
                ++data_read; break;
            case 1:
                ++data_write; break;
            case 2:
                break;
        }
    }

    for(i = 0 ;i < block_num ;++i) {
        if(dirty[i] == true) {
            ++Bto;
        }
    }
    
    printf("Demand fetch:\t%d\n" ,fetch);
    printf("Cache hit:\t%d\n" ,hit);
    printf("Cache miss:\t%d\n" ,miss);
    printf("Miss rate:\t%f\n" , (double)miss / (double)fetch);
    printf("Read data:\t%d\n" ,data_read);
    printf("Write data:\t%d\n" ,data_write);
    printf("Bytes from memory:\t%d\n" ,miss * block_size);
    printf("Bytes to memory:\t%d\n" ,Bto * block_size);
    return 0;
}

int ihtod(char *hex) {
    int i = strlen(hex) - 1;
    int dec = 0;
    while(*hex != '\0') {
        switch(*hex++) {
            case '0':
                dec += 0 << (i-- * 4); break;
            case '1':
                dec += 1 << (i-- * 4); break;
            case '2':
                dec += 2 << (i-- * 4); break;
            case '3':
                dec += 3 << (i-- * 4); break;
            case '4':
                dec += 4 << (i-- * 4); break;
            case '5':
                dec += 5 << (i-- * 4); break;
            case '6':
                dec += 6 << (i-- * 4); break;
            case '7':
                dec += 7 << (i-- * 4); break;
            case '8':
                dec += 8 << (i-- * 4); break;
            case '9':
                dec += 9 << (i-- * 4); break;
            case 'a':
            case 'A':
                dec += 10 << (i-- * 4); break;
            case 'b':
            case 'B':
                dec += 11 << (i-- * 4); break;
            case 'c':
            case 'C':
                dec += 12 << (i-- * 4); break;
            case 'd':
            case 'D':
                dec += 13 << (i-- * 4); break;
            case 'e':
            case 'E':
                dec += 14 << (i-- * 4); break;
            case 'f':
            case 'F':
                dec += 15 << (i-- * 4); break;
        }
    }
    return dec;
}
