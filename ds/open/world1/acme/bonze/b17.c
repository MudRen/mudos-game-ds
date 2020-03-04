// Room: /open/world1/acme/bonze/b17.c

inherit ROOM;

void create()
{
	set("short", "�I��");
	set("long", @LONG
�o�̬O�o�D�����ҩ~���a��A���a�Q�����w�R�A�@�ڲӰw���b
�a�W�A�N���p�q���p��몺�T�G�C�b��W�K�ۤ@�T�r�e�A�W�Y�e�ۤ@
�өM�|�A�M�@�r�y�O�z�A�b�t�@����ѩ^�ۤ@�L������A�o�D���X��
��ԣ��L�C
LONG
	);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"b14",
]));
set("objects",([
    __DIR__"npc/bonze3.c" : 1,
]) );

        set("light",1);
   set("item_desc",([
    "������" : "�@�L�ª����y������A�A��ť��}�}�����n�q�򹳭I��ǥX�H\n",
    ]) );

	setup();
}
int i = 0;
void init()
{
        add_action("do_tune","turn");
}


int do_tune(string arg)
{
        object me,staff;
        staff=new(__DIR__"npc/wp/seven-staff.c");
        me=this_player();
        if(!arg || arg!="������") return 0;
            if(i == 1 || me->query("level")<10 || me->query("class1") != "�ⶳ�x" ) 
                message_vision("$N������F������A�ΤO�a��L���ӡA���G�S������o�{�C\n",me);
        else
        {
                message_vision("$N������F������A�ΤO�a��L���ӡA���G�o�{�F����H�I\n",me);
                staff->move(me);
                i=1;
        }
        return 1;
}
