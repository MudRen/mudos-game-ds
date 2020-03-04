#include <ansi.h> 
inherit ROOM;
void create()
{
        set("short", "�j�|��");
        set("long", @LONG 
�A���B�b�@�|�a�}�̡A�`�ƤQ�ز`�A�X�G�E�Q�ת��ਤ�A�����u
�j���b�~�A���|�����������L���a���٭n�n�A�����D�O�_������F
��H�I 
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
    "up" : "/open/world1/wilfred/sand/room27",
]));
     set("item_desc", ([ /* sizeof() == 1 */
       "�|����" : "�n�n���A�����D�äF����F��H�n���i�H���a(dig)�C\n",
     ]));
         set("no_recall",1);
        set("no_clean_up", 0);

        setup();
}
void init()
{ 
         add_action("do_dig","dig");
}

int do_dig(string arg)
{
        object me,item;
        me=this_player(); 
        if(this_object()->query_temp("DIGED")==1) return notify_fail("��観�H���L�F�C\n");
        if(arg != "�|����") return 0;
        if( me->is_busy() ) return notify_fail("�A���ʧ@�٨S�������C\n");
        else {
                message_vision("$N�ΤO��½�ʧ|�������n�d�g�E�E\n",me); 
                message_vision("����F�I����@����l�F�I\n",me); 
     item=new(__DIR__"npc/obj/mirror");
     item->move(environment(me)); 
                me->start_busy(2);  
                this_object()->add_temp("DIGED",1);
                //call_out("DIG_OUT",5,me); 
                call_out("DIG_TEMP",1000,this_object());
                return 1;
        }
}  
/*
void DIG_OUT()
{
     object me=this_player(),ob=this_object(),item; 
     switch(random(4))     { 
     case 0:
     message_vision("����F�I����@����l�F�I\n",me); 
     item=new(__DIR__"npc/obj/mirror2");
     item->move(environment(me));
     break; 
     case 1:
     message_vision("����F�I����@����l�F�I\n",me);
     item=new(__DIR__"npc/obj/mirror");
     item->move(environment(me)); 
     break;
     }
     return;
} 
*/
void DIG_TEMP()
{
     this_object()->delete_temp("DIGED",1);
     return;
}

