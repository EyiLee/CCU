<div id="sign-in" class="modal fade">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-hidden="true">×</button>
				<h4 class="modal-title">Signin</h4>
			</div>
			<div class="modal-body">
				<form id="sign-in-form" action="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/login.php" method="POST">
					<div class="form-group">
						<label for="sign-in-account">Account</label>
						<input type="text" class="form-control" id="sign-in-account" name="account" placeholder="Account">
					</div>
					<div class="form-group">
						<label for="sign-in-password">Password</label>
						<input type="password" class="form-control" id="sign-in-password" name="password" placeholder="Password">
					</div>
				</form>
			</div>
			<div class="modal-footer">
				<button type="submit" form="sign-in-form" class="btn btn-default">Submit</button>
			</div>
		</div><!-- /.modal-content -->
	</div><!-- /.modal-dialog -->
</div><!-- /.modal -->
<div id="sign-up" class="modal fade">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-hidden="true">×</button>
				<h4 class="modal-title">Signup</h4>
			</div>
			<div class="modal-body">
				<form id="sign-up-form" action="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/register.php" method="POST">
					<div class="form-group">
						<label for="sign-up-name">Name</label>
						<input type="text" class="form-control" id="sign-up-name" name="name" placeholder="Name">
					</div>
					<div class="form-group">
						<label for="sign-up-account">Account</label>
						<input type="text" class="form-control" id="sign-up-account" name="account" placeholder="Account">
					</div>
					<div class="form-group">
						<label for="sign-up-password">Password</label>
						<input type="password" class="form-control" id="sign-up-password" name="password" placeholder="Password">
					</div>
					<div class="form-group">
						<label for="sign-up-confirm">Confirm Password</label>
						<input type="password" class="form-control" id="sign-up-confirm" name="confirm" placeholder="Confirm Password">
					</div>
					<div class="form-group">
						<label for="sign-up-email">Email address</label>
						<input type="email" class="form-control" id="sign-up-email" name="email" placeholder="Email">
					</div>
				</form>
			</div>
			<div class="modal-footer">
				<button type="submit" form="sign-up-form" class="btn btn-default">Submit</button>
			</div>
		</div><!-- /.modal-content -->
	</div><!-- /.modal-dialog -->
</div><!-- /.modal -->
<div id="post-product" class="modal fade">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-hidden="true">×</button>
				<h4 class="modal-title">Post</h4>
			</div>
			<div class="modal-body">
				<form id="post-product-form" action="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/post.php" method="POST">
					<div class="form-group">
						<label for="post-product-title">標題</label>
						<input type="text" class="form-control" id="post-product-title" name="title" required>
					</div>
					<div class="form-group">
						<label for="post-product-content">商品描述</label>
						<textarea class="form-control" id="post-product-content" name="content"></textarea>
					</div>
					<div class="form-group">
						<label for="post-product-connection">聯絡方式</label>
						<textarea class="form-control" id="post-product-connection" name="connection"></textarea>
					</div>
					<div class="form-group">
						<label for="post-product-tag">分類</label>
						<select id="post-product-tag" name="tag">
							<option value="0">交通工具</option>
							<option value="1">書籍</option>
							<option value="2">生活用品</option>
							<option value="3">其他</option>
						</select> 
					</div>
					<div class="form-group">
						<label for="post-product-type">買或賣</label>
						<select id="post-product-type" name="type">
							<option value="0">我要賣</option>
							<option value="1">我想買</option>
						</select> 
					</div>
					<input type="hidden" name="account" value="<?= $_SESSION['login'] ?>">
				</form>
			</div>
			<div class="modal-footer">
				<button type="submit" form="post-product-form" class="btn btn-default">Submit</button>
			</div>
		</div><!-- /.modal-content -->
	</div><!-- /.modal-dialog -->
</div><!-- /.modal -->
<div id="post-product-msg" class="modal fade">
	<div class="modal-dialog">
		<div class="modal-content">
			<div class="modal-header">
				<button type="button" class="close" data-dismiss="modal" aria-hidden="true">×</button>
				<h4 class="modal-title">PostMsg</h4>
			</div>
			<div class="modal-body">
				<form id="post-product-msg-form" action="http://www.cs.ccu.edu.tw/~lchb102u/2015_Spring_SD/final/postmsg.php" method="POST">
					<div class="form-group">
						<label for="post-product-msg-content">留言</label>
						<textarea class="form-control" id="post-product-msg-content" name="content"></textarea>
					</div>
					<input type="hidden" name="account" value="<?= $_SESSION['login'] ?>">
					<input type="hidden" name="pid" value="<?= $_GET['pid'] ?>">
				</form>
			</div>
			<div class="modal-footer">
				<button type="submit" form="post-product-msg-form" class="btn btn-default">Submit</button>
			</div>
		</div><!-- /.modal-content -->
	</div><!-- /.modal-dialog -->
</div><!-- /.modal -->