<header>
	<nav class="navbar navbar-default">
		<div class="container-fluid">
			<!-- Brand and toggle get grouped for better mobile display -->
			<div class="navbar-header">
				<button type="button" class="navbar-toggle collapsed" data-toggle="collapse" data-target="#bs-example-navbar-collapse-1" aria-expanded="false">
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
					<span class="icon-bar"></span>
				</button>
				<a class="navbar-brand" href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/index.php">Trade</a>
			</div>

			<!-- Collect the nav links, forms, and other content for toggling -->
			<div class="collapse navbar-collapse" id="bs-example-navbar-collapse-1">
				<form class="navbar-form navbar-left" role="search">
					<div class="form-group">
						<input type="text" class="form-control" placeholder="Search">
					</div>
					<button type="submit" class="btn btn-default">Submit</button>
				</form>
				<div class="nav navbar-nav navbar-right">
				<?php
					if($admin) {
				?>
					<div class="btn-toolbar">
						<div class="btn-group">
							<button type="button" class="btn btn-default navbar-btn" data-toggle="modal" data-target="#post-product">Post</button>
						</div>
						<a href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/space.php?account=<?= $_SESSION['login'] ?>" class="navbar-text"><?= $_SESSION["login"] ?></a>
						<ul class="nav navbar-nav navbar-right">
							<li><a href="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/logout.php">Logout</a></li>
						</ul>
					</div>
				<?php
					} else {
				?>
					<div class="btn-toolbar">
						<div class="btn-group">
							<button type="button" class="btn btn-default navbar-btn" data-toggle="modal" data-target="#sign-in">Signin</button>
						</div>
						<div class="btn-group">
							<button type="button" class="btn btn-default navbar-btn" data-toggle="modal" data-target="#sign-up">Signup</button>
						</div>
					</div>
				<?php
					}
				?>
				</div>
			</div><!-- /.navbar-collapse -->
		</div><!-- /.container-fluid -->
	</nav>
</header>