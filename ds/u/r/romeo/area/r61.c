// Room: /u/k/king/area/r61.c

inherit ROOM;

void create()
{
	set("short", "[1;31m�԰�[1;33m�ӳ�[2;37;0m������");
	set("long", @LONG
�o�̴N�O���ӳ����̫�@�ݤF�A�|�P�ϦӤ@�ϱ`�A�����R�A�b�s�j��
�Ŷ��̥u��F�@��ç��A�ç����|�P�]���ά�����u���A�����D������
�\�ΡC�Ѫ�O�W�G���F�j����Ϥѯ��L�kť��A���^���A�A�٬O�ۨD�h��
�a�C
LONG
	);
	set("no_recall", 1);
	set("item_desc", ([ /* sizeof() == 1 */
  "����" : "�o�O�@������s�����ä�A�A���G�i�H�ȶ}(uncover)���C
",
]));
	set("world", "undefine");
	set("light", 0);
	set("no_clean_up", 0);

	setup();
}
void init()
{
        add_action("do_uncover","uncover");
}
int do_uncover(string arg)
{
        object me;
        object zombie;
            object zombie2;
        me=this_player();
        if(query_temp("kkzombie")) return notify_fail("����H\n");
        if(arg != "����" )
        {
          notify_fail("�A�n�ȶ}����H\n");
          return 0;
        }
        else {
          message_vision(
          "$N�N���äp�ߪ��ȶ}�A�@�}�®�q�ä�|�P���_����X�ӡA�u���@��
�����s�T���H�w�w���_�C\n\n"
         "���l�ӹ�Ѩg�S�D�G�u�ڪ��@�ɨ��{�F�v�C\n"
         "�@�}������A�@���ѥX�{�b�A���e�B�D�G�u$N�o�ӥ@�ɴN�浹�A�F�v�A�ܲ��A�@���ѴN�����F�C\n"
         ,me);
        zombie=new(__DIR__"npc/chin3.c");
        zombie->move(__DIR__"r61");
        set("exits", ([
          "up" : __DIR__"god",
        ]));
        set_temp("kkzombie",1);
        set("item_desc", ([
        "����" : "�o�ä���G�w�g�Q�H���}�F�C\n",
        ]) );
set("long", @LONG
�A�ݬݳo�ƪ��í�ӬO������A�A����������ä@��A���p�ߧ��ۤv���}�A
�ٵh�F�b�ѡA�̫��٬O�ۤv�N�N��l���Y���F�C
LONG
);
        return 1;
   }
}
