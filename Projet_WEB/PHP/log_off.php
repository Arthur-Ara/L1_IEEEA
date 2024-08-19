<html lang="fr">
    <head>
    <link rel="stylesheet" href="./main.css">
    </head>

    <body>
        <?php
            session_start();
            if ($_SESSION && $_SESSION['hasLogged']) {
                $_SESSION['hasLogged'] = false;
                $_SESSION['email'] = '';
                $_SESSION['username'] = '';
                echo "<p>Vous avez été déconnecté !</p>";
                echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
            }
        ?>
    </body>
</html>