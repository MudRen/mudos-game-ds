inherit NPC;

void create()
{
        set_name("����",({"fisher"}));
        set("long",@LONG
�@��ֽ��K�ª������A���b�@�䦣�ۡC
LONG);
        set("race","�H��");
        set("gender", "�k��");  
        set("age",25+random(10));
        set("level",16+random(4));
        set("attitude","friendly");
        set("chat_chance",10);
        set("chat_msg",({
        "�����@���z�����A�@���˵����S���}�}�C\n",
        "�����N���M���B�z�n�����A�@�����Q�b�ˬ�W�s�����z�C\n",
        "�����N�@�M�Ū����߭˦b���ǡA�o�X�ذճذժ��n�T�C\n",
        }));
        setup();
        add_money("coin",100+random(100));
}
