(define getfactor (lambda (X Y)
    (if (zero? Y)
        `()
        (if (zero? (modulo X Y))
            (cons Y (getfactor X (- Y 1)))
            (getfactor X (- Y 1))))))

(define myfactor (lambda (n)
    (getfactor n n)))

(define getprime (lambda (X Y)
    (if (<= X Y)
        `()
        (if (<= (length (myfactor Y)) 2)
            (cons Y (getprime X (+ Y 1)))
            (getprime X (+ Y 1))))))

(define myprime (lambda (n)
    (getprime n 2)))

(define gettwinprime (lambda (X Y Z)
    (if (zero? X)
        `()
        (if (<= (length (myfactor Z)) 2)
            (if (eq? (- Z Y) 2)
                (cons (list Y Z) (gettwinprime (- X 1) Z (+ Z 2)))
                (gettwinprime X Z (+ Z 2)))
            (gettwinprime X Y (+ Z 2))))))

(define mytwinprime (lambda (n)
    (gettwinprime n 3 5)))
    