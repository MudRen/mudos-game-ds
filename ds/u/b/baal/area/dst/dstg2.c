#include <ansi.h>
#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
        set("short", MAG"�t���w��"NOR);
        set("long", @LONG
��ģ�۾Q�����a�O�K�K�³ª��G�y�������y�ʵۻȦ⪺
���A, �b���̦��@�}�a�T��M�A������ǤF�L��, ���ǽ�
�ߵۤ@�ӥѥժ�, ��ȲV�Xű�����O.
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "south": __DIR__"dstg3",
            "north": __DIR__"dstf1-1",
            ]));
 set("item_desc",([
           "�O":"
�@�ӥѥժ�, ��ȩҲV�Xű�����O, �W�����
        
       �~==================================================��
       | _________________________________________________ |         
       | |                                               | |
       | |   ���ץH���V�B�v�աB�]�k�B���C�R�����Ѫ�      | |
       | |                                               | |
       | |                                               | |
       | |               �������I�I�I                  | |
       | |                                               | |
       | _________________________________________________ |    
       ��=================================================��

\n",
        ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
create_door("north","�ժ���ȲVű��","south",DOOR_CLOSED);
}

