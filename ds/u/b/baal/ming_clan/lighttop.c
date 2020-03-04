#include <ansi.h>
#include <path.h>
inherit ROOM;

int dragon(object me);
int ming(object me);

void create()
{
        set("short", HIR"������"NOR);
        set("long",@LONG
�o�z�O�������A���U�|�P�A��ӳo�̴N�O���W����H�[�����СA��
�ǽݥߤ@���Ӥj���۸O�A�W����D�G�i���Z�L�֤H���A�ߧ�
���пW�B����C�j�e�観�@�y�I�R��Ӫ��c���A�W���g�ۡi�t���c
�j�T�Ӥj�r�A���гХߦܤ��w���G�Q�h�~�A��U�Q�X�U�Ю{�M���U
�a�O�Z�L���Ƥ@�ƤG���j���A�Q�����Щw�O�ת����s�A���ⶳ����
�a�C
LONG
        );
        set("outdoors","land");
        set("light",1);
 set("exits",([ "east": __DIR__"saintming",
    ]));
        set("stroom",1); //�o�˴N���|�M���o�̪��F��.�]���|�A�� (�S���p�~��)
        setup();
}

void init()
{
        ::init();
        ming(this_player());
}

int ming(object me)
{
   object ob;
   if(!userp(me)) // for mob. �קK�O�����۳�ͪ��i�J.
   {
        if(ob=me->query("creater"))
        {
                if( !objectp(present("ming plate",ob)) )
                {
                        message_vision("���бЮ{�j��: �Q�V���N��? ���A���K��j�Y�ڧa�A, $N�A���Ѥl�u�A�����J�h�I�I�C\n"NOR,ob);
                        me->move(TMR_PAST+"area/street5.c");
                        tell_room(environment(me),me->name()+"�Q���бЮ{���F�X�ӡC\n",({ me }));
                        return 1;
                }
        }
   }
    else
   {
        if( !objectp(present("ming plate",me)) && me->query("club/name")!="����" )
        {
        message_vision(HIW"���бЮ{��$N���O���Ъ��в��A�ߧY�N$N�e�ܵ�W�C\n"NOR,me);
                me->move(TMR_PAST+"area/street5.c");
                tell_room(environment(me),me->name()+"�Q���бЮ{���[�F�X�ӡC\n",({ me }));
                return 1;
        }
        
        if( me->query_temp("killer") )
        {
                message_vision("�ѤW�ǨӤ@�ӫիժ��n��: $N, �]���A�����F�H�ҥH�Ȯɤ���i�J�Ф��C\n"NOR,me);
                me->move(TMR_PAST+"area/street5.c");
                tell_room(environment(me),me->name()+"�Q�k�J�Ф��i�O�Q���F�X�ӡC\n",({ me }));
                return 1;
        }
        
        if( me->query_temp("invader") )
        {
                message_vision("�ѤW�ǨӤ@�ӫիժ��n��: $N, �]���A�������L�d���a, �ҥH�Ȯɤ���i�J�Ф��C\n"NOR,me);
                me->move(TMR_PAST+"area/street5.c");
                tell_room(environment(me),me->name()+"�Q�k�J�Ф��i�O�Q���F�X�ӡC\n",({ me }));
                return 1;
        }
        call_out("meeting",2,me);
        return 1;
   }   
}

void meeting(object me)
{
if(!me) return;
        switch( me->query("club/level") )
        {
                case 0:
                case 1:
                        message_vision(HIY"���бЮ{��$N���R"+"�Ю{�жi�I�жi�I\n"NOR,me);
                break;

                case 2:
                        message_vision(HIY"���бЮ{��$N���R"+"�o�����S�̽жi�I�жi�I\n"NOR,me);
                break;

                case 3:
                        message_vision(HIY"���бЮ{��$N���R"+"�@�k�j�H�жi�I�жi�I\n"NOR,me);
                break;

                case 4:
                        message_vision(HIY"���бЮ{�ܦ�§������$N���R"+"��D�j�H�жi�I�жi�I\n"NOR,me);
                break;

                case 5:
                        message_vision(HIY"���бЮ{��$N���`�q§���R"+"�����t�Ϥj�H�z�n�r�I\n"NOR,me);
                break;

                case 6:
                        message_vision(HIY"���бЮ{�ݨ�F$N�A����j�ۡR"+"����ХD�j�H�r��I�I\n"NOR,me);
                break;
        }
        return;
}

