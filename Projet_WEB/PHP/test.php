<html lang="fr">
    <head>
    <link rel="stylesheet" href="./main.css">
    </head>

    <body>
        <?php
            session_start();
        ?>

        <?php if ($_SESSION && $_SESSION['hasLogged']) : ?>
            <p> Vous êtes connectés !</p>
            <FORM action="./log_off.php" method="get" id="formulaire">
                <p><input type="submit" value="Se Déconnecter" id="logoff"></p>
            </form>
        <?php else : ?>
            <p> Vous n'êtes pas connectés !</p>
            <FORM action="./HTML/login.html" method="get" id="formulaire">
                <p><input type="submit" value="Se Connecter" id="logoff"></p>
            </form>
        <?php endif; ?>
    </body>
</html>