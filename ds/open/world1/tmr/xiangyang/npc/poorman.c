// poorman.c

inherit NPC;

void create()
{
        set_name("�a�~", ({ "poor man", "man" }) );
        set("gender", "�k��" );
        set("age", 33);
        set("long", "�@�Ӱ��G�p��A���y��⪺�a�~�C\n");
        set("attitude", "friendly");
//	set("shen", 50);
	set("shen_type", 1);
        set("str", 20);
        set("dex", 18);
        set("con", 17);
        set("int", 13);
        setup();
        set("chat_chance", 15);
        set("chat_msg", ({
"�a�~�i�v�v�a���F�ӫ���C\n",
"�a�~�ĤF�f��G���ǻX�jŶ�l�`�o�ڮa�}�H�`�C\n",
                (: random_move :)
        }) );
}

