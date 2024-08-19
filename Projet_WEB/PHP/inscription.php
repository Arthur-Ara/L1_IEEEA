<html lang="fr">
    <head>
    <link rel="stylesheet" href="./main.css">
    </head>

    <body>
        <?php

            function gotError() {
                echo mysqli_error($connexion);
                echo "<p>Une erreur c'est produite durant votre inscription, veillez contacter l'administrateur.</p>";
                echo "<button onclick=\"window.location.href='../HTML/inscription.html'\">Retourner</button>";
                exit;
            }

            $email = $_GET["email"];
            $username = $_GET["username"];
            $mdp1 = $_GET['mdp'];
            $mdp2 = $_GET['confmdp'];
            if (!$email || !$username || !$mdp1 || !$mdp2) {
                echo "<p>Des informations sont manquantes, votre inscription n'a pas pu être finalisée.</p>";
                echo "<button onclick=\"window.location.href='../HTML/inscription.html'\">Retourner</button>";
                exit;
            }
            if ($mdp1 != $mdp2) {
                echo "<p>Les mots de passe entré sont différents.</p>";
                echo "<button onclick=\"window.location.href='../HTML/inscription.html'\">Retourner</button>";
                exit;
            }

            $connexion = mysqli_connect("db.sciensbot.ovh", "Miklarkz", "unsupermotdepasse", "projet_web", 25565);
            $request = "SELECT * FROM MiPaujekt_User WHERE email = '$email'";
            $request2 = "SELECT * FROM MiPaujekt_User WHERE username = '$username';";
        
            $res = mysqli_query($connexion, $request);
            $res2 = mysqli_query($connexion, $request2);
            if (!$res || !$res2) {
                gotError();
            }
            if (mysqli_num_rows($res) != 0 || mysqli_num_rows($res2) != 0) {
                echo "<p>Ces identifiants sont déjà utilisés.</p>";
                echo "<button onclick=\"window.location.href='../HTML/inscription.html'\">Retourner</button>";
                exit;
            }

            $request = "INSERT INTO MiPaujekt_User VALUES ('$email', '$mdp1', '$username')";
            $res = mysqli_query($connexion, $request);
            if (!$res) {
                gotError();
            }

            echo "<p>Votre compte a été crée ! Vous pouvez désormais vous connecter !</p>";
            echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
            exit;
        ?>
    </body>
</html>