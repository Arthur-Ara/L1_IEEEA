<html lang="fr">
    <head>
    <link rel="stylesheet" href="../CSS/create_task.css">
    </head>

    <body>
        <?php
            session_start();
        ?>

        <?php if ($_SESSION && $_SESSION['hasLogged']) : ?>
            <fieldset>
                <FORM action="./execute_create.php" method="get" id="formulaire">
                    <label>Titre de la Tâche</label>
                    <p><input type="text" id="title" name="title"></p>
                    <label>Description</label>
                    <p><input type="text" id="description" name="description"></p>
                    <label>Date Limite</label>
                    <p><input type="date" id="date" name="date"></p>
                    <label>Status</label>
                    <select name="status"> 
                        <option value="await">A faire</option> 
                        <option value="waiting">En cours</option>
                        <option value="ended">Terminé</option>
                    </select>
                    <p><input type="submit" value="Créer la tâche" id="create_task"></p>
                </form>
            </fieldset>
        <?php else : ?>
            <p> Vous n'êtes pas connectés !</p>
            <FORM action="../HTML/login.html" method="get" id="formulaire">
                <p><input type="submit" value="Se Connecter" id="logoff"></p>
            </form>
        <?php endif; ?>
    </body>
</html>