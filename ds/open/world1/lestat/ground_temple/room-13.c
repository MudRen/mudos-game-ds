#include <ansi.h>
inherit ROOM;

void create()
{
        set( "short", "�a���������") ;
        set( "long", @LONG
�Ѧa�W�_�X���u���A�M�q�n��d�L�Ӫ��p���u�׶����@�Ӥp����
�A�M�����u�����o�X�}�}�M�D���𮧡A�p�G�A���ܻ��o�f�����ꪺ��
�A�������I�u���ѸѴ��A���L�i�O�ܤӦh�F��C
LONG
);
        set("exits", ([ /* sizeof() == 3 */
                  "east" : __DIR__"room-14",
                  "south" : __DIR__"room-09",
                  "west" : __DIR__"room-12",
        ]));
        set("light",0);
        set( "item_desc", ([ /* sizeof() == 1 */
        "����" : "�@�Ӥp����(pool)�C\n",
         ]) );
        set("no_recall","�����������ϳ��B���F�Ҧ����ǰe�O�q�C");
        set("no_clean_up", 0);
        setup();
}

void init() 
{
add_action("drink_water","drink");
}

int drink_water(string str)
{
 int full; 
 object me=this_player(); 
 if( me->query("id") == "guest") return notify_fail("���[��(Guest)����ϥΦ��B�C\n");
 if( !me->query("level") > 15) return notify_fail("�����p�ժ��a�A���B LV 15 �H�U����ϥΡC\n");
 if (str == "water" || str == "pool")
 {
  write("�A�ܤU�F�M�D���u���A�y��ı�o�۷�κZ�A���A�f���C\n");
  full = 5 + this_player()->query("level")*3;
  this_player()->set("talk_point",full);                    //��_tp
  return 1;
 }
// write("�A�Q�ܤ���ڡH\n");
return 0;
 return 1;
}

