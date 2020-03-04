// Room: /u/l/lestia/area/map_6_3.c

inherit ROOM;

void create()
{
	set("short", "�F�۱�-�j�����U");
	set("long", @LONG

�o�̬O�F�۱Фj�U��Ǫ��U��A�M�������q�Ю{�ήȫȷ������a��A�\
�]���`�������@�������A�X�Ө���զ�l�˪��Ю{�����b�Ȥl�W��ѡA�@�i
���q����l�W�\���I�ߡA�A�p�G�j�F�i�H���X���ӦY�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"map_6_2",
  "south" : __DIR__"map_7_3",
]));
	set("current_light", 2);

	setup();
}
void init()
{
   add_action("do_take","take");
}
int do_take(string arg)
{
object obj,me;
    int count,i;
string xx;
    me = this_player();
xx = "/u/l/lestia/area/obj/cookie";
    if( me->query("class1") != "�F�۱�" ) return notify_fail("�A���O�F�۱Ъ��Ю{�A���ள�o���I�ߡC\n");
    if( !arg) return notify_fail("�A�n������H\n");
    //if(sizeof(objectp(present("cookie",me)))>2 ) return notify_fail("�A�ӳg�ߤF�a�A�Y���A���a�C\n");
    if(arg == "cookie" )
    {
        if(objectp(present("cookie",me)))
        {
            for(i=0;i<sizeof(all_inventory(me));i++)
            {
if(base_name(all_inventory(me)[i])==xx) count ++;
                if(count >= 2) return notify_fail("�A�ӳg�ߤF�a�A�Y���A���a!!\n");
            } 
        }
 new(xx)->move(me);
        write("�A�q��W���_�@���������I�ߡC\n");
        return 1;
    }
}


