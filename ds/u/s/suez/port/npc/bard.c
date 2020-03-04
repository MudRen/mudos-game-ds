#include <ansi.h>
inherit NPC;
void create()
{
       set_name(CYN"�u�C�֤H"NOR,({"bard"}));
       set("long",@LONG
    �@�W���v�ƶh���k�ʡA�W�b���ȥH�@�������������]�еۡA���ժ���
��u���۽ݵ^�A�M�ܪ��^�n�w�M�F�A�ߤ����ŵ�A�ӷL�o�S�M�����q�n�~
�ɤF�A���W�����СA�A�u�Q�ѱ��@���A�r�ަb���R���ǻ������C
LONG);
       set("gender","�k��");
       set("age", 27);
       set("level", 50);

       set("chat_chance", 3);
       set("chat_msg", ({
            "�u�C�֤H�����۽ݵ^�A�۵ۡu�Z�^���q���ǻ��v�C\n",
             }));
       set("talk_reply",".....(�N��O�n�A�u�C�֤H���۵ۤZ�^���q���ǻ��A�A�i�H�R�R����ť(listen)�C)\n");
        setup();
}
void init()
{
        ::init();
        add_action("do_listen","listen");
        add_action("do_stop","stop");
}
int do_listen()
{
        object me=this_player();
        int i = random(14)+1;
        if(me->query_temp("fanchins_island_story")>0) return notify_fail("�A�w�g�b��ť�F�C\n");
        tell_object(me,YEL"�A�⨭�鲾�Ӹ��ξA�����աA�}�l��ť�u�C�֤H���q�n�C\n"NOR );
        tell_object(me,"(�t�ۤ��i�H�ϥ�(stop)�פ��ť�C)\n" );
        me->set_temp("fanchins_island_story",1);
        call_out("story",3,me,i);
        return 1;
}
int story(object me,int i)
{
        if(environment(me)!=environment(this_object())) 
        {
                me->delete_temp("fanchins_island_story");
                tell_object(me,"�A�_�����}�F�u�Z�^���q�v�Ȫ��C\n" );            
                return 1;
        }
        if(!me->query_temp("fanchins_island_story")) return 1;
        switch(i)
        {
        case 14:
                tell_object(me,HIB"�b�������ɶ��M�Ŷ����A���ӤZ�^���q�C\n"NOR );break;
        case 13:
                tell_object(me,CYN"���O���������A�O�������l�ͪ����n�x�C\n"NOR );break;
        case 12:
                tell_object(me,HIM"���R���q���H�ά��R���k�l�A�ä��O�Z�H�үਣ�쪺�C\n"NOR );break;
        case 11:
                tell_object(me,HIG"���O�@�W���h�@�����֤k�A�o�b���������o��F���֡C\n"NOR );break;
        case 10:
                tell_object(me,HIY"����e�Ӫ��֤k�A���k�l�Ŭ}���F��F���~�C\n"NOR );break;
        case 9:
                tell_object(me,HIC"���O���p�ڤ۪���l�A���R����H�b�i���U���R�J���C\n"NOR );break;
        case 8:
                tell_object(me,HIR"�@�ѡA�������Ϫ̨ӤF�A�n�N͢��������͢�¼��l���֤k�e���ߩ��C\n"NOR );break;
        case 7:
                tell_object(me,HIW"���r���������}�F�q���·t���D���A�ߩ����D�����n�b����_���C\n"NOR );break;
        case 6:
                tell_object(me,HIY"�������l�N���F�֤k�A�b�{���e�L�o�˪����C\n"NOR );break;
        case 5:
                tell_object(me,HIC"�O�ˤߡA�ڪ��ͩR���|�b�ߩ����u�A��ھԳөR�B�A�N�^��p���ǡC\n"NOR );break;
        case 4:
                tell_object(me,HIG"�֤k����ש��P�}�F�A�d�˪�������ۧ]���۷R�H���`�W�C\n"NOR );break;
        case 3:
                tell_object(me,HIM"�֤k�S���h�F�@���A�u���^�Ъ����l�d�U�C\n"NOR );break;
        case 2:
                tell_object(me,CYN"���_���۵ۡA���_���۵ۡA�������e�o�S�s�˪����l�C\n"NOR );break;
        case 1:
                tell_object(me,HIB"�ɶ������q��������ư��d�A���֤k���b���ݡC\n"NOR );break;
        default:
                tell_object(me,MAG"���ݦo���R�H�A�צ^�ӡA���ݨ��s�˪����l���C�A�C�s�C�ˡC\n"NOR );
                call_out("rest",2,me);
                return 1;
        }
i--;
call_out("story",2,me,i);
}

int rest(object me)
{
        tell_object(me,BLU"���ݦo���R�H�A�צ^�ӡA���ݨ��s�˪����l���C�A�C�s�C�ˡC\n"NOR );
        switch(random(2))
        {
        case 0:
                tell_object(me,YEL"�u�C�֤H�ۧ��A�N�ݵ^��z�@�U�A�R�R���𮧵ۡC\n"NOR );
                me->delete_temp("fanchins_island_story");
                return 1;       
        case 1:
                tell_object(me,YEL"�u�C�֤H�ۧ��A��F�ӽդl�A�S�q�Y�}�l�۰_�C\n"NOR );
                call_out("story",3,me,14);
                return 1;
        }
}

int do_stop()
{
        object me= this_player();
        if(!me->query_temp("fanchins_island_story")) return notify_fail("�A�èS���b��ť�t�ۡC\n");
        me->delete_temp("fanchins_island_story");
        tell_object(me,YEL"�A�����ť�u�C�֤H���t�ۡC\n"NOR );
        return 1;
}
