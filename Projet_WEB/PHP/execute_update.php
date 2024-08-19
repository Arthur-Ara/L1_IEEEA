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
            $id = $_GET['id'];
            $title = $_GET['title'];
            $desc = $_GET['description'];
            $date = $_GET['date'];
            $status = $_GET['status'];
            if ($status == "await") {
                $status = "A faire";
            } else if ($status == "waiting") {
                $status = "En cours";
            } else if ($status == "ended") {
                $status = "Fini";
            }

            $connexion = mysqli_connect("db.sciensbot.ovh", "Miklarkz", "unsupermotdepasse", "projet_web", 25565);
            $request = "SELECT * FROM MiPraujekt_Task WHERE id = '$id';";
            $res = mysqli_query($connexion, $request);

            if (!$res) {
                gotError();
            }

            if (mysqli_num_rows($res) == 0){
                echo "<p>Tâche introuvable</p>";
                echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
                exit;                    
            }  

         if ($title) {
            $request = "UPDATE MiPraujekt_Task SET title = ? WHERE id = ?";
            $stmt = mysqli_prepare($connexion, $request);
            mysqli_stmt_bind_param($stmt, "si", $title, $id);
            $res = mysqli_stmt_execute($stmt);
         }

         if ($desc) {
            $request = "UPDATE MiPraujekt_Task SET description = ? WHERE id = ?";
            $stmt = mysqli_prepare($connexion, $request);
            mysqli_stmt_bind_param($stmt, "si", $desc, $id);
            $res = mysqli_stmt_execute($stmt);
         }

         if ($date) {
            $request = "UPDATE MiPraujekt_Task SET date_limit = '$date' WHERE id = '$id';";
            $res = mysqli_query($connexion, $request);
         }
         if ($status != "default") {
            $request = "UPDATE MiPraujekt_Task SET status = '$status' WHERE id = '$id'";
            $res = mysqli_query($connexion, $request);
         }

         header("Location: ./show_task.php");
         exit();
        ?>
    </body>
</html>