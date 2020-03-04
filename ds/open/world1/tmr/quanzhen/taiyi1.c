// taiyi1.c
// Java Oct.10 1998
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "�ӤA��");
        set("long", @LONG
�A���e�X�{�@�Ӥs����y�A�o�N�O�ۦW���ӤA�� (chi)�A�Ǭ���
���_�~���a�_�y���A�|�P���p���C�A�����Ѫi���y�A�s�����v�A����
�Q���u���C
LONG
        );
        set("outdoors", "zhongnan");
        set("item_desc", ([
                "chi" : 
HIG"\n\n�o�O�@�ӫܤj���s����A�Ѫi���y�A����M�������A���H�Ԥ���Q��(jump)�U�h
�Z�C�@�f�C\n\n"NOR
        ]));
        set("exits", ([
                "southup"   : __DIR__"shandao3",
        ]));

	set("coor/x", -3190);
	set("coor/y", 180);
	set("coor/z", 80);
	setup();
}
void init()
{
        add_action("do_jump","jump");
}
int do_jump(string arg)
{
        object me = this_player();
        object *inv; 
        int c_exp,i;
        c_exp = me->query("combat_exp");
        if( !arg || arg != "chi")
        {
                write("�A�����̸��r? \n");
                return 1;
        }
	inv = all_inventory(me);
        for (i = 0; i < sizeof(inv); i++)
        {
          if (inv[i]->is_character())
             {
              return notify_fail("�A�n���H�ۤv�@�ӤH���a�A�a�ۧO�H�F�ܡH\n");
             }
        }  
        message_vision("$N���ӤA�������h�C\n", me);
        me->move("/d/quanzhen/taiyi2");
        message_vision("$N���i�F�ӤA�����ӡC\n", me);
        return 1;
}
