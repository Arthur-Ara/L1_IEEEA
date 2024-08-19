<html lang="fr">
    <head>
    <link rel="stylesheet" href="./main.css">
    </head>

    <body>
        <?php
            function gotError() {
                echo "<p>Une erreur c'est produite durant votre connexion, veillez contacter l'administrateur.</p>";
                echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
                exit;
            }

            session_start();
            if ($_SESSION && $_SESSION['hasLogged']) {
                $id = $_GET['id'];
                if (!$id) {
                    echo "<p>Une erreur c'est produite</p>";
                    echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
                    exit;
                }

                $connexion = mysqli_connect("db.sciensbot.ovh", "Miklarkz", "unsupermotdepasse", "projet_web", 25565);
                $request = "SELECT * FROM MiPraujekt_Task WHERE id = '$id';";
                $res = mysqli_query($connexion, $request);

                if (!$res) {
                    gotError();
                }

                if (mysqli_num_rows($res) == 0){
                    echo "<p>Tâche introubable</p>";
                    echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
                    exit;                    
                }

                $request = "DELETE FROM MiPraujekt_Task WHERE id = '$id';";
                $res = mysqli_query($connexion, $request);
                if (!$res) {
                    gotError();
                }
                header("Location: ./show_task.php");
                exit();
            } else {
                echo "<p>Une erreur c'est produite, veillez vous reconnecter.</p>";
                echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
                exit;
            }
        ?>
    </body>
</html>