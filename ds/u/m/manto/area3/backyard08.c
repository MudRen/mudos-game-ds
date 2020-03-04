#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "�|�l");
        set("long", @LONG
�o�̰��ۤW�ʰ諸���Y�C�o�ǥ��Y���j���p�A�j�p�@���ЫΡA�p�p
�@���n�J�A�Ϊ��j�h���e��W�ΡC�A�o�{�q���ǥ��Y�������_��(chink)
���ƥX�@�ѪѪ��{����A�ϧA�֭n���äF�C
LONG);
        set("exits", ([
              "southeast" : __DIR__"backyard07",
              "northwest" : __DIR__"backyard09",
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
      		if(me->query_temp("move_stone") > 2)
      		{
      		me->delete_temp("move_stone");
      		me->set_temp("move_wait", 1);
      		me->start_busy(3);
      		call_out("do_wait", 3, me);
        	}     
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
                me->move(__DIR__"chink02");
                message("vision",me->name() + "�q�~���p�F�i�ӡC\n",environment(me), ({me}) );
                return 1;
        }     
}

void do_wait(object me)
{
	object room;
	if(!me || environment(me) != this_object()
	|| !living(me) || !me->query_temp("move_wait")) 
		return;
        message("vision","\n�۬W���M�o�X���n���A�V�@���w�w���}�A�V�U�S�X�@�Ӷ¬}�}���J�f�C\n\n", this_object() );
        set("exits/down", __DIR__"lane01");
        if( room = load_object(__DIR__"lane01") ) {
                room->set("exits/up", __FILE__);
                message("vision","\n�Y���W���۬W���M�o�X���n���A�S�X�@�ӥ��G�G���}�f�C\n\n",room );
                } 
        remove_call_out("close_door");
        call_out("close_door", 5);
}


void close_door()
{
        object room;

        if( !query("exits/down") ) return;
        message("vision","\n�۬W�o�X���n���A�w�w�a���^��B�A�N�V�U���}�f�\\��F�C\n\n", this_object() );
        if( room = load_object(__DIR__"lane01") ) {
                room->delete("exits/up");
                message("vision", "\n�Y���W�o�X���n���A�۬W�S�w�w�a���F�^�h�A��������F�C\n\n", room );
                }
        delete("exits/down");
}

int valid_leave(object me)
{        
       me->delete_temp("move_wait");
       return ::valid_leave(me);
}
