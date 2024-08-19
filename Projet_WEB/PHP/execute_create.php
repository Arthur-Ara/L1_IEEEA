<html lang="fr">
    <head>
    <link rel="stylesheet" href="./main.css">
    </head>

    <body>
        <?php

            function gotError() {
                echo "<p>Une erreur c'est produite durant la création de votre tâche, veillez contacter l'administrateur.</p>";
                echo "<button onclick=\"window.location.href='./create_task.php'\">Retourner</button>";
                exit;
            }

            session_start();
            if ($_SESSION && $_SESSION['hasLogged']) {
                $title = $_GET['title'];
                $desc = $_GET['description'];
                $date = $_GET['date'];
                $status = $_GET['status'];

                if ($status == "await") {
                    $status = "A faire";
                } else if ($status == "waiting") {
                    $status = "En cours";
                } else {
                    $status = "Fini";
                }

                if (strlen($title) > 50) {
                    echo "<p>Le Titre de votre tâche est trop longue !</p>";
                    echo "<button onclick=\"window.location.href='./create_task.php'\">Retourner</button>";
                    exit;
                }

                if (strlen($desc) > 500) {
                    echo "<p>La description de votre tâche est trop longue !</p>";
                    echo "<button onclick=\"window.location.href='./create_task.php'\">Retourner</button>";
                    exit;
                }

                $connexion = mysqli_connect("db.sciensbot.ovh", "Miklarkz", "unsupermotdepasse", "projet_web", 25565);

                $user = $_SESSION['username'];

                $request = "SELECT * FROM MiPraujekt_Task WHERE title = '$title' AND user = '$user';";
                $res = mysqli_query($connexion, $request);
                if (!$res) {
                    echo "Erreur SQL : " . mysqli_error($connexion);
                    gotError();
                } else if (mysqli_num_rows($res) != 0) {
                    echo "<p>Une tâche existe déjà avec ce nom</p>";
                    echo "<button onclick=\"window.location.href='./create_task.php'\">Retourner</button>";
                    exit;
                }

                $request = "INSERT INTO MiPraujekt_Task (title, description, date_limit, status, user) VALUES (?, ?, ?, ?, ?)";
                $stmt = mysqli_prepare($connexion, $request);
                mysqli_stmt_bind_param($stmt, "sssss", $title, $desc, $date, $status, $user);        
                $res = mysqli_stmt_execute($stmt);        
                if (!$res) {
                    echo "Erreur SQL : " . mysqli_error($connexion);
                    gotError();
                }

                header("Location: ./show_task.php");
                exit();

            } else {
                header("Location: ../main.php");
                exit();
            }
        ?>
    </body>
</html>