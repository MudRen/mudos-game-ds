#include <ansi.h>
inherit ROOM;
void create()
{
        set("short",CYN"�O��T��"NOR);
        set("long",@LONG
�Ө�T�ӡA�A�����e���T�@�G�A�j�P�������j���H���ߤ�í�A�s�j
���ѪŴN�b�A���e�i�}�A�ѤW���U�ݡA���Ū����v������a���u�����@
�ݡA�ĺ��Ĵ���i�X�����b�A�ݨӤp���i�R�A�X�������L�ۦb���A��
�����a��A�I�s�ۡA�^�x�ۡC
LONG 
);
        set("exits",([
            "down":__DIR__"port_a2",
                ]));
        set("world","world1");
        set("outdoor","land");
        
        set("item_desc",([
            "����":"�o�Ǯ������A�Q����A���GĲ��i�o(touch)...\n",
            "����":@LONG
�o�Ӿ���O�Ѥ@�Ӷ�L���D�A��L�U���۷�����������զX�A
��L�W�h�ߵۤT�ӥ��j�������A�T�Ӥ������������Ӷ�Ϊ��W
�ѡA��L�W������۹��O��r���u���C�ݾ��񪺼ˤl�A���G��
�g���H�Q�Ұ�(start) ���C
LONG                
                ]));
        setup();
}
void init()
{
        add_action("do_touch","touch");
        add_action("do_start","start");
}
int do_touch(string arg)
{
        object me;
        me=this_player();
        if (arg != "����") return 0;
        else
        {
        message_vision(HIW"�����������~�����F�I�٦b$N��W�d�U�@�b��㳾��j��K���\n"NOR,me);
        return 1;
        }
}
int do_start()
{       
        int i;
        object me;
        me=this_player();
        i =me->query_temp("light_to_future");
        if ( i > 3 || me->query("sarsass")>0) return notify_fail("�b�o���h�u���e�A�A�ä��Q���|�k�ʡC\n");
        else
        {
        tell_object(me,"�A��s�F�@�|��A��M�Ұʾ��񪺤�k�C\n");
         if (i < 3 || !me->query_temp("light_to_future"))
         {
           tell_object(me,"�ݰ_�ӭn�ҰʬO�ܶO�O���ơA�٬O�٬٤O��a�I\n");
            return 1;
         }
         else
         {
           tell_object(me,"�A�J�Ӫ��[��F�@�|��C\n");
           me->start_busy(3);
           tell_object(me,"�A�p���l�l���Ұʾ���C\n");
           me->start_busy(3);
           tell_object(me,"�������Q���B��F�I���U�ӥu�n�����o��(light)�N��F�I\n");
           set("item_desc",([
               "����":"�o�Ǯ������A�Q����A���GĲ��i�o(touch)...\n",
               "����":"�o�Ӿ��񥿶��Q���B��ۡA�쩳�O����O�q�����o����Ӥ����O�H\n"
           ]));
           add_action("do_light","light");
           return 1;
         }
        }
}
int do_light()
{
        int i;
        object me;
        me=this_player();
        i =me->query_temp("light_to_future");
        if ( i > 3 || me->query("sarsass")>0) return notify_fail("�A�Q�_�W�����G�@...�٬O��F�a�I\n");
        if ( i < 3 || !me->query_temp("light_to_future")) return notify_fail("�A�S���ʾ��o�˰��C\n");
        tell_object(me,"�A�b�|�P��M�i�H�o�����F��....\n");
        me->start_busy(1);
        tell_object(me,"�A���@�Ӫo�O�A�o�ӪF�����ӥi�H�Χa�I\n");
        message_vision("$N�q�a�W�߰_�@���o�O....\n",me);
        me->start_busy(1);
        message_vision("$N�N�o�O�I�U��J�T�Ӥ���������....\n",me);
        tell_object(me,HIY"������M��X�@�}���~�I�o�O�����K�������ȡA�]���F��Ӿ���I\n"NOR);
        message_vision(HIR"��x���񳴤J�@������!�@__�@!\n"NOR,me);
        message_vision("$N���򼳷��F���A����]������ʤF....\n",me);
        me->start_busy(1);
        tell_object(me,"�ݰ_�ӬO���ѤF�A�^�h���i�a�I���L���}���~�s���O....�S\n");
        me->set_temp("light_to_future",4);
        set("item_desc",([
            "����":"�o�Ǯ������A�Q����A���GĲ��i�o(touch)...\n",
            "����":"�o�Ӿ��񦳳Q���N�L������....�H\n"
        ]));
        return 1;
}
