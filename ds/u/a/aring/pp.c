inherit ROOM;
int do_add(string arg);
int do_add2(string arg);
int do_add3(string arg);
int do_add4(string arg);
void create()
{
        set("short", "�e��p��");
        set("long", @LONG
�A�����b�e��p���A�u�~�i�ݨ줣�֧������ۤ���ۦb�e��l���@��
�窫�A�]�����ֳ��ȥ��b�ɨ��������ֽ�C���e�]�Q�ޥγq����~���A��
������A�C���򤧮ɡA���e�����o���u�餣���A���٤@���A�A�d�N��e
�䪺���̦��Ӥ��p���i�¬}�j�C
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
            "northeast" : __DIR__"vroad3",
           ]));
        set("outdoors","land");
        set("no_clean_up", 0);
        setup();
//        replace_program(ROOM);
}

void init()
{
        add_action("do_add","add");
        add_action("do_add2","add2");
        add_action("do_add3","add3");
        add_action("do_add4","add4");
}

int do_add(string arg)
{
          object me;
          me=this_player();
            me->add("exp", 1000000);
            me->add("mud_age", 251232);
            me->add("mks",1432);
            me->add("bank",1500000);
          
            return 1;
}


int do_add2(string arg)
{
          object me;
          me=this_player();
            message_vision("$N���¬}����V��F�L�h�C\n",me);
            me->add("combat_exp", 5000);
            me->add("magic_exp", 250000);
                     
            return 1;
}

int do_add3(string arg)
{
          object me, ob, ob2;
          me=this_player();
          ob=this_object();
          ob2=this_object();
            
            ob = new("/obj/saveeq/small_luckbag");
            ob2 = new("/obj/saveeq/symbolbag");
            ob->move(me);
            ob2->move(me);         
            return 1;
}

int do_add4(string arg)
{
        object ob,ppl;
        int i;
        
        ppl = this_player();
                        for ( i=0;i<30;i++ )
                        {
                                ob = new("/obj/symbol/symbol_piece");
                                ob->do_setpiece();
                                ob->move(ppl);
                                message_vision("�@��$N����$n���W!\n",ob,ppl);
                        }
               
                              return 1;
        }


