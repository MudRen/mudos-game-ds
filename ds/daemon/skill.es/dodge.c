// dodge.c

inherit SKILL;

string *dodge_msg = ({
	"���O�M$p$l���F�X�o�C\n",
	"���O�Q$p���F�a���}�F�C\n",
	"���O$n���l�@���M�{�F�}�h�C\n",
	"���O�Q$p�ή��׶}�C\n",
	"���O$n�w���ǳơM���W���������}�C\n",
});

string query_dodge_msg()
{
	return dodge_msg[random(sizeof(dodge_msg))];
}
