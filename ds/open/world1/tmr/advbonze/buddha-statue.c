// Edit By Tmr -2002/1/25-

#include <ansi.h>
#include <path.h>

// ��war ���H��
#define MaxUser 4

inherit ITEM;

nosave object *JoinUser=({});


int query_buddha();
int open_war();
/* �p�Ӧ�n��*/
void end_war();
/* ����war*/
void end_war2();
/* �ⶳ�����U... */
void kneel_bonze()
{
        int i=0;
        object* ob=users();
        for(i=0;i<sizeof(ob);i++)
        {
                if( ob[i]->query("class1")!="�ⶳ�x" ) continue;
                message_vision(HIG "$N�u�P�N�v�@�n���F�U�ӡA�@�ۮ��q�j�n���D�G�u�̤l����p�Ӧ򯪭��{�I�I�v\n" NOR,ob[i]);
        }

}

void open_sun() {
        "/adm/daemons/event/bonze.c"->trigger_event();
}

void checkuser();

void create()
{
        set_name(HIY "�p�Ӫ���" NOR ,({"rulaifo statue","statue"}) );
        set_weight(200000);
        set("long",@LONG
�b�A���e���O�@�L���Q�ƤV�������򹳡A�e�p�N�����A�k�۴L�Y�A�A
���b�򹳪����e�A���h�u����򹳪����\�B�C�p�Ӧ򹳳z�ۤ���Ӯg�A
�{�p�p�Ӳ{�@�����ݡA�A�b�U�V���~�����A���G�N���O�p�Ӧ�{�������
�A���z��k�A�ɥ��޵��C�A���ߤ�����P���A���}���G�N�n���U�F�C
LONG
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","�L");
                set("no_get",1);
                set("no_sac",1);
                set("value",20000);
        }
        setup();
}

void init()
{
        object ob;
        object me=this_player();
        if( objectp(ob=present("_BUDDHA_WAR_BOOK_",me) ) 
                && ob->query("owner_user")==me->query("id")     )
                tell_object(me,HIY "�A���W����Y�߸g�@�}�ݰʡA���G�����v�ۧA�ѥ[(join)����C\n" NOR);
        add_action("do_join","join");

}

int do_join(string arg)
{
        object book;
        object me=this_player();
        int i;
        if(arg!="����")         return 0;
        if(me->is_fighting() || me->is_busy() ) 
                return notify_fail("�A�����ۡA�S���Űѥ[����C\n");
        
        if( !objectp(book=present("_BUDDHA_WAR_BOOK_",me) ) )
                return notify_fail("�A�èS�ѥ[���窺���C\n");
    if( book->query("owner_user")!=me->query("id")      )
                return notify_fail("�A�èS�ѥ[���窺���C\n");
        if(     this_object()->query("open_war") || query_buddha() )
                return notify_fail("�p�Ӧ򯪪�����w�g�b�i�椤�F�C\n");
        
        
        message_vision(HIW "$N���_��Y�߸g�A���q�a�V�򹳥n�F�X���T�Y�A�n�D�ѥ[����C\n" NOR,me);
        checkuser();
        for(i=0;i<sizeof(JoinUser);i++)
                if(JoinUser[i]==me)
                        return notify_fail("�A�w�g�ѥ[����F�C\n");

        JoinUser+=({me});
        message_vision("$N�Q��\\�ѥ[����A�ثe�@��" + sizeof(JoinUser) +"�ӤH�ѥ[�C\n",me);
        destruct(book);

        checkuser();
        // �H�ư��F�A�}War
        if(sizeof(JoinUser)==MaxUser)
        {
                set("open_war",1);
                message_vision(HIY "�p�Ӫ��򹳵o�X�@�}�Q��ģ�������~......\n" NOR,me);
                call_out("open_war",3);
        }
        return 1;
}

int open_war()
{
        int i;
        object g;
                string username="";

                set("open_war",1);
                //�� �|����Npc
                // ����
                g=new(__DIR__"npc/buddha1");
                g->move(__DIR__"summit2");
                // �j�O
                g=new(__DIR__"npc/buddha3");
                g->move(__DIR__"summit3");
                //��N
                g=new(__DIR__"npc/buddha2");
                g->move(__DIR__"summit5");
                //���
                g=new(__DIR__"npc/buddha4");
                g->move(__DIR__"summit4");

                 // �|��npc ����b�P�@��
                  g=new(__DIR__"npc/buddha1");
                  g->move(__DIR__"summit1");
                  g=new(__DIR__"npc/buddha2");
                  g->move(__DIR__"summit1");
                  g=new(__DIR__"npc/buddha3");
                  g->move(__DIR__"summit1");
                  g=new(__DIR__"npc/buddha4");
                  g->move(__DIR__"summit1");

                  g=new(__DIR__"npc/bonze");
                  g->move(__DIR__"summit2");
                  g=new(__DIR__"npc/bonze");
                  g->move(__DIR__"summit3");
                  g=new(__DIR__"npc/bonze");
                  g->move(__DIR__"summit4");
                  g=new(__DIR__"npc/bonze");
                  g->move(__DIR__"summit5");
                   g=new(__DIR__"npc/buddha5");
                   g->move(__DIR__"summit6");



                for(i=0;i<sizeof(JoinUser);i++)
                        username+=JoinUser[i]->query("name") + " ";
        message("world:world1:vision",
  HIY "\n\n��b�ⶳ�p���W��" +username + "���|�H���q���Ŧ򸹹D�G\n\n" + HIW

+"\t�u�� �� �K �M �A �W �o �L �q�F\n"
+"\t  �o �j �� �� �A �� �� �@ ���F\n"
+"\t  �@ �N �� �� �� �L �q �W�A\n"
+"\t  �O �� �� �� �� �� �j �֡C�v\n"
+HIM "\n\n�p�Ӧ򯪯d�U���W����ۦ��}�l�F�C\n\n" NOR
        ,users() );

                call_out("end_war",10);
        return 1;
}

/* �p�Ӧ򯪡@�n�� */
void end_war()
{
        object g;
        object buddha;
                checkuser();
                //�ѥ[�H�Ƥ���
                if(sizeof(JoinUser)<MaxUser) 
                {
                message("world:world1:vision",
                HIC "\n�i��������j�ⶳ�p���W�i�椤���W����]������̪��k�צӤ��_�F�I�I\n\n" NOR
                                ,users() );
                        set("open_war",0);
                        JoinUser=({});
                                 // �M���Ҧ�War Npc
                                while( objectp(buddha=find_living("buddha-war-jingang")) )
                                {
                                        if( !environment(buddha) )
                                        {
                                                    destruct(buddha);
                                                        buddha = 0;
                                                        continue;
                        }
                                tell_room(buddha,HIW "�ѤW�g�U�@�D�զ���~�]��F"+buddha->query("name")+"�A�H�Y�����b�A���e�I�I" NOR);
                                destruct(buddha);
                                buddha = 0;
                                } // end while
              return;
                        } // end if

                        if( query_buddha()  )
                          call_out("end_war",30);
                        else {
                        /* �p�Ӧ򯪡@�n�� */
                        g=new(__DIR__"npc/rulaifo");
                        g->move(__DIR__"summit1");

                message("world:world1:vision",
                 HIG "\n\n�i��������j�ⶳ�p���W����U�V�A�j�O�j�d���p�Ӧ򯪲{���H�@���F�I�I\n\n" NOR 
                ,users() );
                        // �� �ⶳ�� ���̤l���U����
                        kneel_bonze();
                call_out("end_war2",10);
                        }       
        return;
}

void end_war2()
{
        object buddha;
                object book;
                int i;
        
                checkuser();
                //�ѥ[�H�Ƥ���
                if(sizeof(JoinUser)<MaxUser) 
                {
                message("world:world1:vision",
                HIC "\n�i��������j�ⶳ�p���W�i�椤���W����]������̪��k�צӤ��_�F�I�I\n\n" NOR
                                ,users() );
                        set("open_war",0);
                        JoinUser=({});
                        // �M���Ҧ�War Npc
                while( objectp(buddha=find_living("buddha-war-jingang")) )
                    {
                if( !environment(buddha) )
                {
                        destruct(buddha);
                        buddha = 0;
                                                continue;
                }
                                tell_room(buddha,HIW "�ѤW�g�U�@�D�զ���~�]��F"+buddha->query("name")+"�A�H�Y�����b�A���e�I�I" NOR);
                                destruct(buddha);
                                buddha = 0;
                        }
                        return;
                }

                if( query_buddha()  )
                          call_out("end_war2",30);
        else {
                message("world:world1:vision",
    HIG"\n\n�i��������j�u���ĲM�D��A�`�C�����šA���ͤ߫��b�A�д���{�e�C�v\n" 


+HIC "\n\t�ⶳ�p���W���W���秹�������F�I�I\n\n" NOR
                        ,users() );
                                // ���C����̪����c��
                                for(i=0;i<sizeof(JoinUser);i++)
                                {
                                        if(!JoinUser[i]) continue;
                                        book=new(__DIR__"npc/obj/jingang-book");
                                        tell_object(JoinUser[i],HIB "�g�L�p�Ӧ򪺬~§�A�A���ߤ���󬰵������Y�S��`�@�h�F�C\n" NOR);
                                        tell_object(JoinUser[i],"�A�����W���M�h�F�@������I�H\n" NOR);
                                        book->move(JoinUser[i]);
                                            JoinUser[i]->add("evil",-300);

                                }
                set("open_war",0);
                                JoinUser=({});
                 // �۵M�_�[�G�ⶳ�p����X
                  call_out( "open_sun", 60 + random(30));
        }       
        return;
}

int query_buddha()
{
        object buddha;

        while( objectp(buddha=find_living("buddha-war-jingang")) )
        {
                if( !environment(buddha) )
                {
                        destruct(buddha);
                        buddha = 0;
                }
                else break;
        }

        if( objectp(buddha) ) return 1;
        else return 0;
}

void checkuser()
{
        int i;
        for(i=0;i<sizeof(JoinUser);i++)
                if( !JoinUser[i] )      JoinUser-=({JoinUser[i]});
}

