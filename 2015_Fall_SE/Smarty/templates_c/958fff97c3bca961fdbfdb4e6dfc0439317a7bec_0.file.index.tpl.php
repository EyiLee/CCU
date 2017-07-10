<?php /* Smarty version 3.1.27, created on 2015-10-29 13:46:41
         compiled from "/.amd_mnt/cs1/host/csdata/home/under/u102/lchb102u/WWW/2015_Fall_SE/Smarty/templates/index.tpl" */ ?>
<?php
/*%%SmartyHeaderCode:187624185956322341ccfa15_43748700%%*/
if(!defined('SMARTY_DIR')) exit('no direct access allowed');
$_valid = $_smarty_tpl->decodeProperties(array (
  'file_dependency' => 
  array (
    '958fff97c3bca961fdbfdb4e6dfc0439317a7bec' => 
    array (
      0 => '/.amd_mnt/cs1/host/csdata/home/under/u102/lchb102u/WWW/2015_Fall_SE/Smarty/templates/index.tpl',
      1 => 1446126540,
      2 => 'file',
    ),
  ),
  'nocache_hash' => '187624185956322341ccfa15_43748700',
  'variables' => 
  array (
    'hello' => 0,
    'str1' => 0,
    'str2' => 0,
    'str3' => 0,
    'str4' => 0,
    'str5' => 0,
    'str6' => 0,
    'str7' => 0,
    'fav' => 0,
    'i' => 0,
    'vi' => 0,
    'room' => 0,
    'vj' => 0,
  ),
  'has_nocache_code' => false,
  'version' => '3.1.27',
  'unifunc' => 'content_56322341d9f5f7_47877008',
),false);
/*/%%SmartyHeaderCode%%*/
if ($_valid && !is_callable('content_56322341d9f5f7_47877008')) {
function content_56322341d9f5f7_47877008 ($_smarty_tpl) {
if (!is_callable('smarty_modifier_replace')) require_once '/.amd_mnt/cs1/host/csdata/home/under/u102/lchb102u/WWW/2015_Fall_SE/Smarty/plugins/modifier.replace.php';
if (!is_callable('smarty_modifier_capitalize')) require_once '/.amd_mnt/cs1/host/csdata/home/under/u102/lchb102u/WWW/2015_Fall_SE/Smarty/plugins/modifier.capitalize.php';
if (!is_callable('smarty_modifier_date_format')) require_once '/.amd_mnt/cs1/host/csdata/home/under/u102/lchb102u/WWW/2015_Fall_SE/Smarty/plugins/modifier.date_format.php';

$_smarty_tpl->properties['nocache_hash'] = '187624185956322341ccfa15_43748700';
?>
<!doctype html>
<html>
	<head></head>
	<body>
		<?php echo smarty_modifier_replace($_smarty_tpl->tpl_vars['hello']->value,"hello","Hello World!");?>
<br>
		<?php echo smarty_modifier_capitalize($_smarty_tpl->tpl_vars['str1']->value);?>
<br>
		<?php echo ($_smarty_tpl->tpl_vars['str2']->value).("Information and Engineering");?>
<br>
		<?php echo smarty_modifier_date_format($_smarty_tpl->tpl_vars['str3']->value,"%Yyear%mmonth%dday");?>
<br>
		<?php echo (($tmp = @$_smarty_tpl->tpl_vars['str4']->value)===null||$tmp==='' ? "NA" : $tmp);?>
<br>
		<?php echo preg_replace('!^!m',str_repeat("*",8),$_smarty_tpl->tpl_vars['str5']->value);?>
<br>
		<?php echo strtolower($_smarty_tpl->tpl_vars['str6']->value);?>
<br>
		<?php echo smarty_modifier_replace(smarty_modifier_replace($_smarty_tpl->tpl_vars['str7']->value,"No","Have"),"no","have");?>
<br>

		<table border="1">
		<?php
$_from = $_smarty_tpl->tpl_vars['fav']->value;
if (!is_array($_from) && !is_object($_from)) {
settype($_from, 'array');
}
$_smarty_tpl->tpl_vars['vi'] = new Smarty_Variable;
$_smarty_tpl->tpl_vars['vi']->_loop = false;
$_smarty_tpl->tpl_vars['i'] = new Smarty_Variable;
foreach ($_from as $_smarty_tpl->tpl_vars['i']->value => $_smarty_tpl->tpl_vars['vi']->value) {
$_smarty_tpl->tpl_vars['vi']->_loop = true;
$foreach_vi_Sav = $_smarty_tpl->tpl_vars['vi'];
?>
			<?php if ((1 & $_smarty_tpl->tpl_vars['i']->value)) {?>
			<tr style="background-color:#DDD">
			<?php } else { ?>
			<tr>
			<?php }?>
				<td><?php echo $_smarty_tpl->tpl_vars['i']->value;?>
</td>
				<td><?php echo $_smarty_tpl->tpl_vars['vi']->value;?>
</td>
			</tr>
		<?php
$_smarty_tpl->tpl_vars['vi'] = $foreach_vi_Sav;
}
?>
		</table>

		<select>
		<?php
$_from = $_smarty_tpl->tpl_vars['room']->value;
if (!is_array($_from) && !is_object($_from)) {
settype($_from, 'array');
}
$_smarty_tpl->tpl_vars['vj'] = new Smarty_Variable;
$_smarty_tpl->tpl_vars['vj']->_loop = false;
$_smarty_tpl->tpl_vars['j'] = new Smarty_Variable;
foreach ($_from as $_smarty_tpl->tpl_vars['j']->value => $_smarty_tpl->tpl_vars['vj']->value) {
$_smarty_tpl->tpl_vars['vj']->_loop = true;
$foreach_vj_Sav = $_smarty_tpl->tpl_vars['vj'];
?>
			<option><?php echo $_smarty_tpl->tpl_vars['vj']->value;?>
</option>
		<?php
$_smarty_tpl->tpl_vars['vj'] = $foreach_vj_Sav;
}
?>
		</select>
	</body>
</html>
<?php }
}
?>