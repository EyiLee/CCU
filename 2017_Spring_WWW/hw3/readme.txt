Student Name: 李佳祥
Class ID: 402410078
Description:
    (a)
        use bootstrap & JQuery
    (b)
        Users (
            id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARYKEY,
            username VARCHAR(30),
            password VARCHAR(128)
        )

        Postz (
            id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARYKEY,
            uid INT UNSIGNED,
            FOREIGN KEY(uid) REFERENCES Users(id),
            filename VARCHAR(255),
            filepath VARCHAR(255),
            updatetime timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
        )

        Commentzz (
            id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARYKEY,
            pid INT UNSIGNED,
            FOREIGN KEY(pid) REFERENCES Posts(id),
            uid INT UNSIGNED,
            FOREIGN KEY(uid) REFERENCES Users(id),
            content text,
            updatetime timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP
        )

        Like (
            id INT UNSIGNED NOT NULL AUTO_INCREMENT PRIMARYKEY,
            pid INT UNSIGNED,
            FOREIGN KEY(pid) REFERENCES Posts(id),
            uid INT UNSIGNED,
            FOREIGN KEY(uid) REFERENCES Users(id),
        )
    (c)
        URL: dmplus.cs.ccu.edu.tw:49404/hw3/index.php
    (d)