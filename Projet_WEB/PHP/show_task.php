<html lang="fr">
    <head>
    <link rel="stylesheet" href="../CSS/show_task.css">
    </head>

    <body>
        <?php
            session_start();

            function gotError() {
                echo "<p>Une erreur c'est produite durant la récupération de vos tâche, veillez contacter l'administrateur.</p>";
                echo "<button onclick=\"window.location.href='./create_task.php'\">Retourner</button>";
                exit;
            }
        ?>

        <?php if ($_SESSION && $_SESSION['hasLogged']) : ?>
            <div class="container">
                <div class="button-container">
                    <FORM action="./create_task.php" method="get" id="formulaire">
                        <p><input type="submit" value="Créer une nouvelle tâche" id="create_task"></p>
                    </form>
                </div>
                <div class="button-container">
                    <FORM action="./show_task.php" method="get">
                        <p><input type="submit" value="Trier par Date" id="date_limit" name="sort_by_date"></p>
                    </form>
                </div>
                <div class="button-container">
                    <FORM action="./show_task.php">
                        <p><input type="submit" value="Trier par Status" id="sort_by_status" name="sort_by_status"></p>
                    </form>
                </div>
                <div class="button-container-right">
                    <FORM action="../main.php">
                        <p><input type="submit" value="Retourner à l'Accueil" id="back_home"></p>
                    </form>
                </div>
            </div>

            <?php
                $user = $_SESSION['username'];
                if(isset($_GET['sort_by_date'])) {
                    $request = "SELECT * FROM MiPraujekt_Task WHERE user = '$user' ORDER BY date_limit ASC";
                } 
                elseif (isset($_GET['sort_by_status'])) {
                    $request = "SELECT * FROM MiPraujekt_Task WHERE user = '$user' ORDER BY status ASC";
                } 
                else {
                    $request = "SELECT * FROM MiPraujekt_Task WHERE user = '$user'";
                }

                $connexion = mysqli_connect("db.sciensbot.ovh", "Miklarkz", "unsupermotdepasse", "projet_web", 25565);
                $res = mysqli_query($connexion, $request);

                if (!$res) {
                    gotError();
                }

                echo "<div class='contenu'>";
                echo "<dl>";

                if (mysqli_num_rows($res) == 0){
                    echo "<p class='no-task-message'>Vous n'avez aucune tâche</p>";
                    exit;
                }

                $counter = 0;

                while ($etu = mysqli_fetch_array($res)) {
                    ++$counter;
                    echo "<fieldset>";
                    echo "<dt id = 'task-container'><strong>Tâche n°$counter -</strong> {$etu['title']}<br><br><strong>Descriptif :</strong><br><br>{$etu['description']}<br><br><strong>Date limite :</strong> {$etu['date_limit']}<br><strong>Status :</strong> {$etu['status']}</dt>";
                    echo "<br>";
                    echo "<button onclick=\"window.location.href='./update_task.php?id={$etu['id']}'\">Modifier</button>";
                    echo "<button onclick=\"window.location.href='./delete_task.php?id={$etu['id']}'\">Supprimer</button>";
                    echo "</fieldset>";
                    echo "<br><br>";
                }
            ?>


        <?php else : ?>
            <p> Vous n'êtes pas connectés !</p>
            <FORM action="../HTML/login.html" method="get" id="formulaire">
                <p><input type="submit" value="Se Connecter" id="logoff"></p>
            </form>
        <?php endif; ?>
    </body>
</html>