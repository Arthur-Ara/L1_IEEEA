<html lang="fr">
    <head>
    <link rel="stylesheet" href="./main.css">
    </head>

    <body>
        <?php

            function gotError() {
                echo "<p>Une erreur c'est produite durant votre connexion, veillez contacter l'administrateur.</p>";
                echo "<button onclick=\"window.location.href='../HTML/login.html'\">Retourner</button>";
                exit;
            }

            $email = $_GET["identifiant"];
            $mdp = $_GET['mdp'];
            if (!$email || !$mdp) {
                echo "<p>Toutes les informations n'ont pas été remplis, impossible de vous connecter.</p>";
                echo "<button onclick=\"window.location.href='../HTML/login.html'\">Retourner</button>";
                exit;
            }


            $connexion = mysqli_connect("db.sciensbot.ovh", "Miklarkz", "unsupermotdepasse", "projet_web", 25565);

            if(strpos($email, "@gmail.com") || strpos($email, "@univ-rouen.fr")) {
                $request = "SELECT * FROM MiPaujekt_User WHERE email = '$email' AND password = '$mdp';";
                $res = mysqli_query($connexion, $request);
                if (!$res) {
                    gotError();
                }
                if (mysqli_num_rows($res) == 0) {
                    echo "<p>Impossible de vous connecter, veillez vérifier votre Email et votre mot de passe.</p>";
                    echo "<button onclick=\"window.location.href='../HTML/login.html'\">Retourner</button>";
                    exit;
                }

                $res = mysqli_fetch_assoc($res);
                session_start();
                $_SESSION['hasLogged'] = true;
                $_SESSION['email'] = $res['email'];
                $_SESSION['username'] = $res['username'];
                
                echo "<p>Vous avez été connecté</p>";
                echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
                exit;
            } else {
                $request = "SELECT * FROM MiPaujekt_User WHERE username = '$email' AND password = '$mdp';";
                $res = mysqli_query($connexion, $request);
                if (!$res) {
                    gotError();
                }
                if (mysqli_num_rows($res) == 0) {
                    echo "<p>Impossible de vous connecter, veillez vérifier votre Username et votre mot de passe.</p>";
                    echo "<button onclick=\"window.location.href='../HTML/login.html'\">Retourner</button>";
                    exit;
                }

                $res = mysqli_fetch_assoc($res);
                session_start();
                $_SESSION['hasLogged'] = true;
                $_SESSION['email'] = $res['email'];
                $_SESSION['username'] = $res['username'];
                
                echo "<p>Vous avez été connecté</p>";
                echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
                exit;
            }
        ?>
    </body>
</html>