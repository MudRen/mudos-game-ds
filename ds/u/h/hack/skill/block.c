// parry.c

inherit SKILL;

string *block_msg = ({
	"�u��v�@�n�M�Q$p��$s�פU�F�C\n",
	"���G�u���v�a�@�n�Q$p�ήɥ�$s�׶}�F�C\n",
	"���O�Q$n��$s�[�}�C\n",
	"�u��$n���W�����a�Τ⤤��$s��}�F�C\n",
});


string query_block_msg(object shield)
{
 string result,shield_name;
 
 	if(shield) shield_name = shield->query("name");
 	else shield_name = "�޵P";
 	result = block_msg[random(sizeof(block_msg))];
	result = replace_string( result, "$s", shield_name );
	return result;
}
