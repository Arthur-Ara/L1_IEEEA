<html lang="fr">
    <head>
    <link rel="stylesheet" href="../CSS/create_tasK.css">
    </head>

    <body>
        <?php
            function gotError() {
                echo "<p>Une erreur c'est produite durant votre connexion, veillez contacter l'administrateur.</p>";
                echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
                exit;
            }

            session_start();
        ?>
        <?php if ($_SESSION && $_SESSION['hasLogged']) : ?>
            <?php
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
            ?>     
            <fieldset>
                <p>Ecrivez uniquement dans la/les zone(s) que vous souhaitez modifier</p>
                <FORM action="./execute_update.php" method="get" id="formulaire">
                    <input type="hidden" name="id" value="<?php echo $id ?>">
                    <label>Titre de la Tâche</label>
                    <p><input type="text" id="title" name="title"></p>
                    <label>Description</label>
                    <p><input type="text" id="description" name="description"></p>
                    <label>Date Limite</label>
                    <p><input type="date" id="date" name="date"></p>
                    <label>Status</label>
                    <select name="status"> 
                        <option value="default"></option> 
                        <option value="await">A faire</option> 
                        <option value="waiting">En cours</option>
                        <option value="ended">Terminé</option>
                    </select>
                    <p><input type="submit" value="Modifier la tâche" id="update_task"></p>
                </form>
            </fieldset>          
        <?php else : ?>
            <?php
                echo "<p>Une erreur c'est produite, veillez vous reconnecter.</p>";
                echo "<button onclick=\"window.location.href='../main.php'\">Retourner</button>";
                exit;
            ?>
        <?php endif; ?>
    </body>
</html>