#include <ansi.h>
#include <path.h>
inherit ROOM;
void callmob1();
void callmob2();
void callmob3();
void callmob4();
void end_war();
void start_war();


string *place=({"street3","street4","street5","street6","street2",
                "plaza","plaza1","plaza2","plaza3","plaza4",
                "pathway1","pathway2","smallway","ndoor","edoor","wdoor","sdoor" });
string *place2=({"bigwall","door2","door1","passage1","passage2","passage3",
                "room2","room2","bigdoor","way1","way2","way3","yidoor",
                "path1","path2","path3","path4","path5","path6","path7",
                "path8","path9","hall"});
string *garrison=({"soldier","general","lu","gu","chung",
                   "general2","chief","chief2","leader","lord"});


void create()
{
        set("short", "����");
        set("long", @LONG
�o�̴N�O�ѫ�������F�A����W���ۿ��ѷݡA���󪺤G�ǯ��ۤ@
�ƪ��x�L�A��W���۪O�l�M�P�l�A�A�i�H�ݨ��P�l�W�g�ۡu�ªZ�v�B
�u���R�v�A�ݨӧA�o�ĨĪ��O�x�ơA�]����b�o�̤j�ۤj�s�A�_�h�|
�Q�@���I
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"path3",
]));
set("objects",([
     __DIR__"npc/gou.c" : 1,
    __DIR__"npc/garrison.c" : 4,
]) );
        set("light",1);

        setup();
}

void start_war()
{
        int i;
        object g;
//�h�L(soldier)  -> 15 ��
//���N(general)  -> 10 ��
//�t�N(general2) ->  7 ��
//�ʤҪ�(chief)  ->  5 ��
//�d�Ҫ�(chief2) ->  4 ��
//�`�L(leader)   ->  3 ��
//���`(lord)     ->  2 ��
//����(lu)       ->  1 ��
//����(gu)       ->  1 ��
//�L�R(chung)    ->  1 ��
//------------------------
//�X�p(total)    -> 49 ��

        for (i=0;i<=10;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[0]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        } //�ѫ��̪�-->�h�L(soldier)

        for (i=0;i<=5;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[0]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        }//�Ū��̪�-->�h�L(soldier)

     call_out("callmob1",20);
//   call_out("end_war",60);
    return;
}
void callmob1()
{
        int i;
        object g;
        for (i=0;i<=5;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[1]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        }//�ѫ��̪�-->���N(general)

        for (i=0;i<=5;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[1]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        }//�Ū��̪�-->���N(general)

     call_out("callmob2",20);
     return;       
}
void callmob2()
{
        object g;
        int i;
        for (i=0;i<=5;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[5]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        }//�ѫ��̪�-->�t�N(general)

        for (i=0;i<=2;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[5]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        }//�Ū��̪�-->�t�N(general)

     call_out("callmob3",20);
     return;
}
void callmob3()
{
        object g;
        int i;

        for (i=0;i<=3;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[6]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        }//�ѫ��̪�-->�ʤҪ�(chief)

        for (i=0;i<=2;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[6]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        }//�Ū��̪�-->�ʤҪ�(chief)

     call_out("callmob4",20);
     return;
}
void callmob4()
{
        object g;
        int i;
        for (i=0;i<=3;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[7]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        }//�ѫ��̪�-->�d�Ҫ�(chief2)

        g=new(ACME_PAST+"cominging/npc/"+garrison[7]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        //�Ū��̪�-->�d�Ҫ�(chief2)

        for (i=0;i<=2;i++)
        {
        g=new(ACME_PAST+"cominging/npc/"+garrison[8]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        }//�ѫ��̪�-->�`�L(leader)

        g=new(ACME_PAST+"cominging/npc/"+garrison[8]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        //�Ū��̪�-->�`�L(leader)

        g=new(ACME_PAST+"cominging/npc/"+garrison[9]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        //�ѫ��̪�-->���`(lord)

        g=new(ACME_PAST+"cominging/npc/"+garrison[9]);
        g->move(ACME_PAST+"cominging/"+place2[random( sizeof(place2) )] );
        //�Ū��̪�-->���`(lord)

        g=new(ACME_PAST+"cominging/npc/"+garrison[2]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        //�ѫ��̪�-->����(lu)

        g=new(ACME_PAST+"cominging/npc/"+garrison[3]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        //�ѫ��̪�-->����(gu)

        g=new(ACME_PAST+"cominging/npc/"+garrison[4]);
        g->move(ACME_PAST+"area/"+place[random(sizeof(place))] );
        //�ѫ��̪�-->�L�R(chung)
     call_out("end_war",500);
     return;
}
void end_war()
{
        object npc;
        object e,s,n,w;
        if(objectp(npc=find_living("skycitywar") ) )
{
                 if(!environment(npc)) destruct(npc);
                  call_out("end_war",30,0);
        }
        else {
                message("world:world1:vision",
        HIY   "\n     �T�x�Q���o�줣���x�A�ɯɰk�R�h�A�]�}�ҤF�����C\n\n"  NOR
                ,users() );
//            find_object(ACME_PAST+"area/ndoor")->unlock_door("north",1);
//            find_object(ACME_PAST+"area/sdoor")->unlock_door("southdown",1);
//            find_object(ACME_PAST+"area/edoor")->unlock_door("east",1);
//            find_object(ACME_PAST+"area/wdoor")->unlock_door("southwest",1);
        n=find_object(ACME_PAST+"area/ndoor");
        e=find_object(ACME_PAST+"area/edoor");
        w=find_object(ACME_PAST+"area/wdoor");
        s=find_object(ACME_PAST+"area/sdoor");
n->unlock_door("north");
e->unlock_door("east");
w->unlock_door("southwest");
s->unlock_door("southdown");
          this_object()->delete("Sky-City-War");
        }
return;
}

void init()
{ 
//     add_action("do_shout","shout")
}
int do_shout(string arg)
{
        int i,j;
        object me;
        me=this_player();
        if( !arg ) return notify_fail("�A�Q�n�j�s����?\n");
        if( !wizardp(me) )
        {
                if( me->query("mp") < 15 )
                        return notify_fail("�A����O����, �S���������O��ۥs�C\n");
                me->add("mp",-15);
        }
      message_vision("$N�Q�n�b�o�̤j�q�j�s�A��O�Q���ѷݬݯ}�F�C\n",me);
        if( me->query_temp("SKYCITY/shout") > 1 )
        {
                message_vision("���ѷݳܹD�G"+me->query("name")+"�I�I�A��a�p���x�T�A�𦺧ڤF�I\n",me);
                message_vision("���ѷݳܹD�G�ӤH�ڡI�I��"+me->query("name")+"���j�c���F�I�I\n",me);
                message_vision("�G�Ǩ��X�|�өx�L�N$N�㨫�F�I\n",me);
                me->move(__DIR__"injail");
        }
        else {
                switch( random(2) ) {
                        case 0:
                        j=me->query_temp("SKYCITY/shout");
                        message_vision("���ѷݻ��D�G�x�I�H$N�x���H������I�H\n",me);
                        message_vision("���ѷݻ��D�G�ӤH�ڡI�I��"+me->query("name")+"�������Q���j�O�I�I\n",me);
                        message_vision("�T��x�L���F�L�ӡA�N$N�j���b�a�W�A���������F�Q���j�O�I�I\n",me);
                        me->receive_damage("hp",45);
                        me->set_temp("SKYCITY/shout",j+1);
                        break;

                        case 1:
                        i=me->query("wound/head");
                        j=me->query_temp("SKYCITY/shout");
                        message_vision("���ѷݻ��D�G�x�I�H$N�x���H������I�H\n",me);
                        message_vision("���ѷݻ��D�G�ӤH�ڡI�I��"+me->query("name")+"�������x�L�Q�U�C\n",me);
                        message_vision("�T��x�L���F�L�ӡA�N$N�j���b�a�W�A�������x�F�Q�U���L�C\n",me);
                        me->set_temp("SKYCITY/shout",j+1);
                        me->set("wound/head",i+10);
                        break;
                }
        }
        return 1;
}
