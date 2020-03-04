inherit ROOM;
void create()
{
        set("short","�۶�");
        set("long",@LONG
�A���b���~���۶��A�A�����e�N�O���A���~�𪺹��˶V���W�N
�V����A�O�H�P�Ĩ�@�̪��\�O�l���«C�A�ӤW�����j��]�V�ӶV�h�A�o
�̪����˦��G�O�e�ۤ@�إͪ��A�F�����@�ӥۥx�A�譱�h�O�@�h�h���۶�
�C
LONG
        );
  
        set("exits", ([
            "east" : __DIR__"zk12",
            "west" : __DIR__"zk9",
            ]));
        set("no_clean_up", 0);
        set("outdoors","land");
        set("item_desc", ([
            "����" : "�@�T�����_�Ǫ��ϵe�A�@���u���@�b���s�]�\\�i�H��F��ӦX��(meld)�C\n",
            ]));        
         setup();
}

void init()
{
        add_action("do_meld","meld");
}


int do_meld(string arg)
{
        object me,obj,ob,fodoor;
        ob=this_object();
        me=this_player();
        fodoor=load_object(__DIR__"fodoor");
        if(me->is_busy()) return notify_fail("�A�����ۡA�S�ŧ@��L�ơC\n");
        if(arg!="����" || !arg )
        {
                notify_fail("�A�n�X�֤���?\n");
                return 0;
        }
        if(fodoor->query("put_dragon",1)) return notify_fail("�w�g�X�ֹL�F");
        if(obj=present("halfdragon stone",me))
        {
                              
                  message_vision("$N�N$n����˦X�Ӭ��@�F�C\n",me,obj);
                  destruct(obj);
                  set("item_desc", ([
                      "����" : "�@�T�J�յ��s���ϵe�C\n",
                      ]));
                  fodoor->set("put_dragon",1); //�]�аO     
                  return 1;
        }
         else
        {
                tell_object(me,"�A���W�S���i�H�X�֪��F���\n");
                return 1;
        }
}

void reset()
{
        object fodoor=load_object(__DIR__"fodoor");
        if(fodoor->query("testtime")); return;
        set("item_desc", ([
            "����" : "�@�T�����_�Ǫ��ϵe�A�@���u���@�b���s�]�\\�i�H��F��ӦX��(meld)�C\n",
            ]));            return ::reset();
}






