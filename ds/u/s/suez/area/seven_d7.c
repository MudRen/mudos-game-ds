#include <ansi.h>
inherit ROOM;

void create()
{
 set("short","���");
        set("long",@LONG
�o�̬ݰ_�ӤQ�����b�A�n�����H�`�`�ӥ����C��񪺤j���Q�H�J�Ӫ�
�ΦǪd�ʦ�A�ݨӬO�i���h�F�C�j���W�����B�g�ۺK�P���A��Ǫ��۷ण
���D�Q����F�襴��A�ʤF�@�j���A�u�ۤj����Ǫ��𨤳������F����A
���G�O��N���������A�n���Q�⤰��h�W���^�оB���_�Ӥ@��C
LONG
        );
  set("item_desc",([
       "����":"�b���������󤤦n�����Ǥ���F��C\n",
       "�۷�":"�Q�����F�@�j���A���ӬO�Q�K��V�����C�ʤf�����䦳�t���⪺����A�n���O��C
�ݰ_�ӬO����q�W�۷�A�A���H�N�Q���q�W�����@�������@��C\n",
       "�j��":"�Q�Ǫd�ʦ�F�A�i���h�C���B�W�g�ۺK�P���A��\�\\�i�H����񪺤H��ť��ť(inquiry)�C\n",
                            ]));
        set("outdoors","land");
        setup();
 }
void init()
{
        add_action("do_search", "search");
        add_action("do_roll", "roll");
}
int do_search(string arg)
{
        object me;
        me=this_player();

        if (arg != "����" )
                return 0;
        else 
        {
         message_vision( HIY "$N�b���󤤵o�{�F�@�Ӥp�g��A�n��(dig)�ܡH\n\n" NOR ,me);
         add_action("do_dig","dig");
         return 1;
        }
}
int do_dig(string arg)
{
        object me;
        me=this_player();

        if(arg != "�p�g��" && arg !="�g��") return 0;
        else 
        {
         message_vision(HIG"$N�q�g�襤���X�F�@��V�媺�ۤ��C\n"NOR,me);  
         tell_object(me,HIB"�A�N�o�ǥۤ�����_�ӡA���M�o�{�W���W�F�@���A���O��L���ˤl�I\n"NOR);
         tell_object(me,HIB"�ݨӳo��L���D�H�j���Ӿ��A�A\��\�\\��\�լd�ݬݡC\n"NOR);
         me->add_temp("quest/pick_star",1);
         message_vision(HIG"$N��ۤ����s�I�^�h�C\n"NOR,me);
         return 1;
        }
}     
int do_roll(string arg)
{
        int t;
        object me;
        me=this_player();
        if(arg != "�۷�") return 0;
        else{
        message_vision( HIG "$N��ʤF�۷�A��M�}�U���a�O���F�}�ӡI$N�N�o�˱��U�h�F�I�I\n\n" NOR ,me);
        me->start_busy(3);
        message_vision( HIG "$N��ӤH�����b�}����A�a�O�S�L�n�L�����W�F�A�۷�]��_�F�쪬�C\n\n" NOR ,me);
        me->move(__DIR__"secret");
        return 1;
         
}
}