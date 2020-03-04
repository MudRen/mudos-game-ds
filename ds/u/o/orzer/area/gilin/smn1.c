inherit ROOM;
void create()
{
        set("short","�s�V�W");
        set("long",@LONG
�A���W�F�s�V�W�A�s�V�W�i�H�ݨ�\�h�������A�A�o�{�s�V����
���٦��@���˪L�A�u�O�H��]�S�O�@�p�A�٦��۸޲����q�n�A���A����
�ۥD���S�ݰ_�ӭn���n�U�h�@�@�A�s�V�W�����۳\�h���j���Y�C
LONG
        );
        set("exits", ([
  "down" : __DIR__"t27",
]));
        set("item_desc", ([
            "���Y" : "�@���Z�j�����Y�A�ݨӫD�`í�T�A�]�\\�i�H�Τ���F��j��(ties_up)���H\n",
         ]));  
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
}


void init()
{
 add_action("do_ties_up","ties_up");
 add_action("do_slip","slip");
}


int do_ties_up(string arg)
{
        object me,obj,ob;
        ob=this_object();
        me=this_player();
        if(me->is_busy()) return notify_fail("�A�����ۡA�S�ŧ@��L�ơC\n");
        if(arg!="���Y" || !arg )
             return notify_fail("�A�n�j����?\n");
        if(query("tiesup_rope"))
             return notify_fail("�W���w�g�j�n��÷�F\n");         
        if(obj=present("rope",me))
        {
                              
                  message_vision("$N�N$n�c�c���j�W�F���Y�W���C\n",me,obj);
                  destruct(obj);
                  set("item_desc", ([
                      "���Y" : "�@���Z�j�����Y�A�ݨӫ�í�T�A�W���j�F��÷�]�\\�i�H�ƤU(slip down)�s�V�C\n",
                      ]));
                  ob->set("tiesup_rope",1);  //�]�аO                 
                  return 1;
        }
         else
        {
                tell_object(me,"�A���W�S���i�H�j���F���\n");
                return 1;
        }
}
 
int do_slip(string arg)
{        
        object me; 
        me=this_player();
        if (!query("tiesup_rope"))
        return 0;
        if (!arg || arg =="" || arg!="down")
        return notify_fail("�A�n�ƨ���H\n");  
        if( me->is_busy() )
               return notify_fail("�A�٦b���I\n");
        message_vision("$N�ܫi������_��÷���s�V�U�ơI",me); 
        if (me->query_dex() >= 50){  
        message_vision("�A$N�Q���W�����q�s�V�ƤF�U�h\n",me);
        me->move(__DIR__"t29"); 
        tell_room(environment(me), "�s�V�W���H�v�U���A��ӬO"+me->name()+"�q�s�V�W�ƤU�ӡA���ջ��F�I\n", ({ me }));
        return 1;
        } 
            message_vision("�A$N�@�Ӥ��p�߱q�s�V�����F�U�h\n",me);
            me->receive_wound("left_leg",5+random(20));
            me->receive_wound("right_leg",5+random(20));
            me->receive_wound("left_arm",5+random(20));
            me->receive_wound("right_arm",5+random(20));
            me->receive_wound("head",5+random(20));
            me->receive_wound("body",5+random(20));             
             me->receive_damage("hp",me->query("hp")*1/3);
            me->move(__DIR__"t29.c");
           
            tell_room(environment(me), "�y���@�n�A"+me->name()+"�q�s�V�W���F�U�ӡA�ݨӨ��ˤ��L�I\n", ({ me }));            return 1;
}

void reset()
{
        set("item_desc", ([
            "���Y" : "�@���Z�j�����Y�A�ݨӫD�`í�T�A�]�\\�i�H�Τ���F��j��(ties_up)���H\n",
         ]));
        delete("tiesup_rope");       
        return ::reset();
}







