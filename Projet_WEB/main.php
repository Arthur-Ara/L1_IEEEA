<!DOCTYPE html>

<html lang="fr">
	
	<head>
		<meta charset="utf-8" />
		<title>Gestion des Tâches</title>
        <link rel="stylesheet" href="./CSS/main_bis.css"/>
	</head>

	<body>

	        <?php
                session_start();
            ?>

            <?php if ($_SESSION && $_SESSION['hasLogged']) : ?>
                <form action="./PHP/show_task.php" method="get" id="show_task">
                    <p id= "test"><input type="submit" value="Voir mes Tâches" id="show_task"></p>
                </form>
                <form action="./PHP/log_off.php" method="get" id="log_off">
                    <p><input type="submit" value="Se Déconnecter" id="Connect"></p>
                </form>
            <?php else : ?>

                <FORM action="./HTML/inscription.html" method="get" id="formulaire">
                    <p><input type="submit" value="Inscription" id="Inscription"></p>
                </form>
                <FORM action="./HTML/login.html" method="get" id="formulaire">
                    <p><input type="submit" value="Se Connecter" id="Connect"></p>
                </form>

            <?php endif; ?>

		<br><br>

		<p id ="Titre">Qu'est-ce que MyPraujekt ?</p>

		<br>

		<p id ="Paragraphe">
			My Praujekt est un site web qui vous permet de recenser toutes vos tâches à faire dans votre journée,<br> de pouvoir les trier par date et par statut,
			c'est-à-dire si la tâche est finie, en cours ou bien pas encore commencée.
		</p>

		<br>

		<p id ="Titre">Pourquoi utiliser MyPraujekt ?</p>

		<br>

		<p id ="Paragraphe">
			MyPraujekt est un site web à l'utilisation extrêmement simple.Il vous suffit de créer un compte en utilisant le bouton "Inscription" <br> situé en
			haut à droite de votre écran, puis de saisir un pseudo,une adresse e-mail et un mot de passe.<br> Une fois cela fait, vous pouvez utiliser notre
			site web pour planifier toutes vos tâches.
		</p>

		<br>

		<p id ="Titre" >D'ou vient l'idée de MyPraujekt ?</p>

		<br>

		<p id ="Paragraphe">
			Nous avons tous connu cette période où nous sommes envahis par diverses tâches à faire et où nous ne savons plus où donner de la tête ni comment
			répartir nos tâches.<br> En tant que créateurs de ce site, nous sommes régulièrement confrontés à ce problème.C'est pourquoi nous avons décidé
			de créer MyPraujekt afin de mieux <br>nous organiser et de vous permettre également de mieux vous organiser.
		</p>

		<hr />
        <a href="https://www.youtube.com/watch?v=dQw4w9WgXcQ">
            <img src="./Images/Facebook.png" alt = "Logo Facebook" width="50px" height ="50px"/>
            <br>

            <img src="./Images/Instagram.png" alt ="Logo Instagram" width ="50px" height ="50px"/>
            <br>

            <img src="./Images/LinkedIn.png" alt ="Logo Linkedin" width ="50px" height="50px"/>
            <br>

            <img src="./Images/X.png" alt="Logo X" width="50px" height="50px"/>
        </a>

        <p id = "TML">Mention Légales :</p>

        <p id = "ML">
            Nom de l'entreprise : MiPraujeckt <br>
            Au capital de -1$ <br>
            Métropole de Rouen <br>
            Siège Social : Ma résidence <br>
            Ce site est hébergé par mon voisin résidant à droite de ma résidence
        </p>
	</body>
	
</html>
