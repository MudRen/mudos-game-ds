//this room ���ܤj��Bug @@ ~ 
//�ܰ�,����ù��

#include <ansi.h>

#define MOB_DIR __DIR__"npc/"
inherit ROOM;

int move_mob(); // �Y�n�b���ɤ��� move_mob()�ofunction�h�Ұʤ��̤��e,�������bcreate()�e,inherit��[�@�[�o��

void create()
{
        set("short", HIB"�a�U�ӥ�"NOR);
        set("long", @LONG
���Ф@�ˬO���t�����A���e������W���G���ۤ@�i�y�A�@�i�c�]
���y�A�b�]�y���|�P���������~�����A�q��~��{�b�A�n�������ܦh 
�������b�ݵۧA�A���G�b���ݤ���A�o�طPı�A�N���O���g�L����
���K�Ȫ�����@�ˡA�]�y���G�o�X�@�}�}���ݮ��n�A�o��ۧA���ߡA
���ѷQ���]�����Y�A���ݵۧA�h�l��(wakeup)�C
LONG
   );
        set("exits", ([ /* sizeof() == 3 */
  "southeast" : __DIR__"room-5",
  "southwest" : __DIR__"room_5", 
  "south" : __DIR__"room4",
]));  
        set("no_light",1);
        set("no_clean_up", 0);
        setup();
}
void init()
{
        add_action("do_wakeup","wakeup"); 
//        add_action("do_kill_evil","kill_evil");     �S���Χa! - del by -alick
}
int do_wakeup(string ob)
{
    object a,b;  
    object room;
    a=this_player();
        if( ob =="evil" && !query_temp("opened") ) // "wakeup" id �S�� - alick
{
    message_vision(HIC"\n\t$N���۹D:�ݧ����]�A�H���ѹD ! ! \n"NOR,a);
    message("world:world1:vision", HIR"\n\t���]�g��D:�ݧ��]�N��F�A�ٷQ���]�A���Ӥ����Ѱ��a�p���p�� !!\n"NOR,users());
    b=new(__DIR__"npc/evil");
    b->move(this_object() );
// delete_temp("wakeup"); �����S����! ,cancelled -alick
        set_temp("opened", 1);
        move_mob(); // Run move_mob()��func
        call_out("reborn", 900); //15 x 60 = 900 sec
    return 1;
    }
    else
    {
    message_vision(HIG"\n\t$N�Q������]�A�i�O���]�n���S���򿳽�...\n"NOR,a); 
    }
    return 1;
}
int move_mob() // string a �S��,int i �e���V�c,�ХξA���W�r
{
    object ob;
    int i;

    string *mobs= ({ "shield-guard", "helmet-guard", "mask-guard", "neck-guard","armor-guard","cloth-guard",
                     "cloak-guard","hands-guard","gloves-guard","finger-guard","waist-guard","pants-guard",
                     "leggings-guard","boots-guard"
                  });   
        object room= load_object(__DIR__"room5"); // load_object()�̭n�D���O���ɦW
             for(i=0;i<14;i++) {  
             if( !objectp( ob = find_object(MOB_DIR+mobs[i]) ) ) continue;   // find_object�n���ɦW
             if( ob->move(room) ) message_vision("$N���o�̽ĤF�L�ӡA�B���a����A�D�G���]�A�ǩR�ӡI�I�C\n", ob);   
             if(ob->move(room))
                ob->kill_ob(present("evil", this_object()));
             }   
             return 1;    
}

int reborn()
{
        delete_temp("opened");
        return 1;
}

