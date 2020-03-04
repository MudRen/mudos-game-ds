#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�|�l");
        set("long", @LONG
�o�̰��ۤW�ʰ諸���Y�C�o�ǥ��Y���j���p�A�j�p�@���ЫΡA�p�p
�@���n�J�A�Ϊ��j�h���e����ΡC�A�o�{�q���ǥ��Y�������_��(chink)
���ƥX�@�ѪѪ��{����A�ϧA�֭n���äF�C
LONG);
        set("exits", ([
              "southeast" : __DIR__"backyard08",
        ]));
         set("item_desc", ([                    
                "chink": "\n�_�ظ̭����¤@���A�����������F�F���n�T�C\n",
        ]));

        setup(); 
}

void init()
{
    	object me = this_player();
		  	if(me->query_skill("anti_poison", 1) < 50)
//            me->apply_condition("snake_poison", me->query_condition("snake_poison") + 5);
        add_action("do_enter", "enter");
 
}

int do_enter(string arg)
{
        object me = this_player();

        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("�A�����۩O�C\n");
        if( !arg || arg=="" ) return 0;

        if (arg == "chink" ){   
        	message_vision("$N�S�}�_�ؤf���åۤl�A�@�s�y���_�ظ��p�F�i�h�C\n",me);
                me->move(__DIR__"chink03");
                message("vision",me->name() + "�q�~���p�F�i�ӡC\n",environment(me), ({me}) );
                return 1;
        }     
}
