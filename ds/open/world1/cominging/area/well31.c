#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "�p�s��");
        set("long", @LONG
�@�y��󫰤������p�s���A�s�������Ӥj�������ѵ��H�ܤ��ΡA�_��
�O�y����A���F�h�O�q�����a�W�ӡu�¤Ѵ�v�A���֪��ȫȱq�F�䨫�ӡA
�ѥL���y�W��ߡB�g�ߪ����A�A���T���}�u�¤Ѵ�v���Ӵ��C������N
�s�����F���f�C
LONG
        );  
              set("hide_exits", ([ /* sizeof() == 6 */
                  "fuck" : __DIR__"well32",
                        ]));

        set("objects", ([ /* sizeof() == 1 */
           __DIR__"gold-man":10 ,
         ]));
        set("outdoors","land");
        set("light",1);
        set("no_clean_up", 0);
        setup();

}
void init()
{
        add_action("do_take","take"); 
        add_action("do_take2","take2");
}
int do_take(string arg)
{
        object me, p;
        me = this_player();
        if( arg != "�������� "&& arg !="rob" ) return 0;
                {
                p=new(__DIR__"gcflower");
                p->move(this_player()); 
                    return 1; 
} 
}
int do_take2(string arg)
{
        object me, p;
        me = this_player();
        if( arg != "�������� "&& arg !="hbb" ) return 0;
                {
                p=new("/open/world1/acme/area2/npc/obj/you_ming_book.c");
                p->move(this_player()); 
                    return 1; 
} 
}

