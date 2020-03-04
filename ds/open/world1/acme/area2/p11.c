// Room: /u/a/acme/area3/p11.c
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "�D�F");
	set("long", @LONG
�o�O�@�y�۳y�D�F�A�D�F�������Ӷ��ۤj��A�|��h���|������j��
�H��Ȥl�ϥΡA�b�D�F�~���Ӥp����A�|�P���p���A�ʪ��v�v�A�⭻�L
���A�A�R�p�e�C�b�D�F�����ۮ�W�A��ۤ@�L���U�����H�ѡA��M�o�L�H
�Ѥw�ର�@�L�ӴѡA��Ĺ�]�b�@��ؤ����A������H���N���L�U���A�ӯd
�ѩ󦹡A�u�O�H��i�ҫ�C
LONG
	);
       set("light",1);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"p7",
]));
set("objects",([
      __DIR__"npc/yi2" : 1,
]) );
 set("item_desc", ([ /* sizeof() == 1 */
"�H��" :    "        ��  ��  ��  ��  ��  ��  ��  ��  ��\n"
            "      A  ---------------"HIB"�N"NOR"------"HIB"�H"NOR"-------\n"
            "        ��  ��  ��  ���@������  ��  ��  ��\n"
            "      B "HIR"��"NOR"----------"HIR"�L"NOR"--"HIR"�L"NOR"----------"HIB"��"NOR"--- \n"
            "        ��  ��  ��  �������@��  ��  ��  ��\n"
            "      C  ---------------"HIB"�H"NOR"---------------     �o�O�@�L���U�����ѡA\n"
            "        ��  ��  ��  ��  ��  ��  ��  ��  ��    �γ\\�A�i�H(grasp)�h\n"
            "      D  --------------------------------     �����o�L���������ѡC\n"
            "        ��  ��  ��  ��  ��  ��  ��  ��  ��    �ҡGgrasp 5a move 6a�A\n"
            "      E  --------------------------------     �o�B�O�ϡu�N�v���k���@��C\n"
            "        ��    "HIC"��  �e          �~  ��"NOR"    ��\n"
            "      F  -------------------------------- \n"
            "        ��  ��  ��  ��  ��  ��  ��  ��  ��\n"
            "      G  ---------------"HIB"�]"NOR"---------------\n"
            "        ��  ��  ��  ��  ��  ��  ��  ��  ��\n"
            "      H  -------"HIB"��"NOR"------"HIR"��"NOR"--------------- \n"
            "        ��  ��  ��  ���@������  ��  ��  ��\n"
            "      I  -----------"HIB"��"NOR"--"HIR"�K"NOR"--------------- \n"
            "        ��  ��  ��  �������@��  ��  ��  ��\n"
            "      J "HIB"�]"NOR"--------------"HIR"��"NOR"--"HIR"�K"NOR"-----------\n"NOR,
]));
	setup();
}
void init()
{
        add_action("typegrasp","grasp");
}
int typegrasp(string arg)
{
        object me;
        me=this_player();
        if(arg != "5b move 5a") return notify_fail("�A�oı�o�˨��n������C\n");
        else {
        message_vision("$N���Ť誺�u�N�v�Y���F�C\n" ,me);
        message_vision("$N�oı�ۮण�����̰ʡA���h�ɡA�ۮ�}�H�F�A�B�X�{�F�ӤJ�f�C\n",me);
           set("exits", ([ /* sizeof() == 1 */
              "north" : __DIR__"p7",
              "down" : __DIR__"t",
           ]));
        set("item_desc", ([ /* sizeof() == 1 */
"�H��" :    "        ��  ��  ��  ��  ��  ��  ��  ��  ��\n"
            "      A  ---------------"HIR"�L"NOR"------"HIB"�H"NOR"-------\n"
            "        ��  ��  ��  ���@������  ��  ��  ��\n"
            "      B "HIR"��"NOR"----------"HIR"�L"NOR"----------------"HIB"��"NOR"--- \n"
            "        ��  ��  ��  �������@��  ��  ��  ��\n"
            "      C  ---------------"HIB"�H"NOR"---------------\n"
            "        ��  ��  ��  ��  ��  ��  ��  ��  ��\n"
            "      D  --------------------------------\n"
            "        ��  ��  ��  ��  ��  ��  ��  ��  ��\n"
            "      E  --------------------------------\n"
            "        ��    "HIC"��  �e          �~  ��"NOR"    ��\n"
            "      F  -------------------------------- \n"
            "        ��  ��  ��  ��  ��  ��  ��  ��  ��\n"
            "      G  ---------------"HIB"�]"NOR"---------------\n"
            "        ��  ��  ��  ��  ��  ��  ��  ��  ��\n"
            "      H  -------"HIB"��"NOR"------"HIR"��"NOR"--------------- \n"
            "        ��  ��  ��  ���@������  ��  ��  ��\n"
            "      I  -----------"HIB"��"NOR"--"HIR"�K"NOR"--------------- \n"
            "        ��  ��  ��  �������@��  ��  ��  ��\n"
            "      J "HIB"�]"NOR"--------------"HIR"��"NOR"--"HIR"�K"NOR"-----------\n"NOR,
]));
        return 1;
       }
}
int valid_leave(object me, string dir)
{
       if( dir=="down" && !userp(me) )
                return notify_fail("���̥u�����a�~��i�h�C\n");
        return ::valid_leave(me, dir);
}
