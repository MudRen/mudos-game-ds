// Room: /open/world1/tmr/freezetaoism/downroad4.c
#include <ansi.h>
        inherit ROOM;

void create()
{
        set("short", "�a�U����");
        set("long", @LONG
�㶡�K�����۫ǥR���ۤ@�ѻD�����R����{���A�@�檺�����O�|�B
��«�A�ո̤���ť���H���x�������n�C�b���Ǥ����\��ۤ@�Ӥj�K�c�A
�K�c�l�W�K�K�³¦a�K���F�ũG�A�\�l�W�٦��ө_�ΩǪ������ѡC
LONG
        );
        set("current_light", 2);
        set("exits", ([ /* sizeof() == 1 */
          "north" : __DIR__"downroad3",
        ]));
        set("no_clean_up", 0);
        set("no_recall",1);
        set("item_desc",([
        	"����":"�@�Ӭ����J�f�j�몺���ѡA���b�K�c�\\�l�W�A��������γB�C\n",
        ]));
        setup();
}

void init()
{
        add_action("do_insert","insert");
}

int do_insert(string arg)
{
        object me=this_player(),ob,wp;
        if(!arg) return 0;
        if(arg!="staff into ����") return 0;
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("�A�����ۡA�S���Ű��o�ʧ@�C\n");
        if(query_temp("clone_tian_demon" ) ) return 0;
        
        // ���ϥ� �C�C����(seven staff)
        if(!objectp(wp=present("_SEVEN_STAFF_",me)) )
        {
                if(objectp(wp=present("staff",me) ) )
                {
                        //�ϥΨ�L��������
                        message_vision("$N�N$n"NOR"���J��c�l�W�����ѡA���O�èS������Ƶo�͡C\n",me,wp);
                        return 1;
                }
                else return 0;
        }
        
        //�ѧ� (tian demon)
        ob=find_living("_NPC_TIAN_DEMON_");
        // �ѧ��w�g�X�{�F
        if( objectp(ob) ) {
                // �ѧ��b���X�k���ж�
                if(!environment(ob) ) {
                        destruct(ob);
                } else {
                        message_vision("$N�N$n"NOR"���J��c�l�W�����ѡA���O�èS������Ƶo�͡C\n",me,wp);
                        return 1;
                }
        }
        // �s�X �ѧ� 
        message_vision(CYN "$N�N$n"CYN"íí�a���J��c�l�W�����ѤW......�C\n",me,wp);
        message_vision(HIR "\n$n"+HIR"�W��O�O���ƤQ�����F���G�s�T���_�d�A�b��y�K�Ǹ̯e�t�a�y«�I�I\n\n"NOR,me,wp);
        set_temp("clone_tian_demon",1);
        call_out("clone_tian_demon",3,me);
        me->add_busy(2);        
        //�R�� �C�C���� �C��
        destruct(wp);
        return 1;
}

int clone_tian_demon(object me)
{
        object ob=new(__DIR__"npc/tian-demon");
        if(!ob ) {
                message_vision(CYN"�̫ᤰ��Ƥ]�S���o�͡C\n"NOR,me);
                delete_temp("clone_tian_demon");
                return 1;
        }
        message_vision(
                HIY "\n�ƹD���~�q�K�c�l���E�g�X�ӡA�y«�����F�v�@�a�����b��Ť���...\n"NOR
                + HIM "\n���M����j���A�㶡�۫Ǽ@�P�a�n�ʰ_�ӡA�Ѩ���E�����H�νw�w�X�{�b�A���e�I\n\n"NOR
        ,me);
        ob->move(__DIR__"downroad4" );
        delete_temp("clone_tian_demon");
        return 1;
}


