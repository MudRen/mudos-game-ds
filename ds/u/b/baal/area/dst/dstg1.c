#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", MAG"�t���w��x�|"NOR);
        set("long", @LONG
�������t���w�𥿽ݥߦb���e, �@�����`�۾Q�����p�|
��L�x�|, �q�V���ѯ»Ȼs��, �ժ��^�䪺�j��, �p�|���
���R��������H�Pı����u�C�֤H�f���ұԭz���ؤ@�w���H
�ۥj�𪺳��˴˪��Pı, ��Ǫ��ᦷ�b�A�ʤH, �O�H���Q�N
���K�U���İ�.
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north": __DIR__"dstg3",
            ]));
 set("item_desc",([
           "�ᦷ":"�p�|��Ǫ���c�U���d��, ���۰��v, �ѳ��O�A�S���L���~��, �A���q�߲z���w�W�o��
, ���ؤ��޳o�y�𪺥D�H�|���|�Ǹo���Q�n�K(pick)�@���U�Ӫ�����.\n",
           "�j��" : "�@���򳬵۪��j��, �W�õL�j��, �ݨӦ��G����Y�}(pull), ���D
�O, �Ѫ��D�������]�k���b�W��?\n",
                 ]));
        set("outdoors","land");
        set("objects", ([
  __DIR__"npc/reciter1" : 2,
]));

        set("no_clean_up", 0);
        setup();
}

int room_effect(object me)
{

         switch(random(6))
        {
         case 0:
         write("�@�����������������b�A�Y�W�L�ۤF���, �w�w�����V�x�|���t�@�Y\n");
         tell_object(me, HIY "�@�}�H�H���խ��p�i�F�A����l, �߮ɥO�H�P��q��κZ�C\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write("�A�L�N���ݨ�p�|�W���@����ģ�ۦ��G�{�F�@�U..... \n");
         tell_object(me, HIC "�@���C�쩿�a�q�ᦷ�����F�X��, ��A�u�f�ʡI�v���s�F�@�n, �H�Y�Ʀ��@�λ���, �����F...\n" NOR ); 
         return 1;

         case 2:
         write("�@�}�L���}�}�۫��j��... \n");
         tell_object(me, RED "�@�����Y�N�ֳt���q�A�Y�W�C���ӹL�I�I\n" NOR ); 
         return 1;

case 3:
         write("�A�ݨ����誺�ѪťX�{�F�@�Ӷ��I, ���I�w�w���a��, ��ӬO�@���Q�~�C \n");
         tell_object(me, HIW "�Q�~���L�A���Y�W, �u�P�I�v���@�n, �@�Υզ�, �H�Y�����j�K���b�A�Y�W...:Q\n" NOR ); 
         return 1;

case 4:
         write("���O�̶ǨӤ@�}�̰ʡI�H... \n");
         tell_object(me, HIB "�@�����ץu��A���\\���j�H�S�R�����b�k, �Q�@�����������⪺�ѹ��l��...\n" NOR ); 
         return 1;

case 4:
         write("�@����ģ�ۥ۪O�w�w�����W��, �Q���F�}��... \n");
         tell_object(me, HIG "�@�����ۯͻH�Ȧ⪺�p�s�����F�W��, ���s��۶��Q�n, �H�Y�@���ۡuA dear John Letter�v�@��i�}�ͻH���W��...\n" NOR ); 
         return 1;

         default:       return 1;
        }
}

void init()
{
        add_action("typepick","pick");
        add_action("typepull","pull");
}
     int typepick(string arg)
{
        object me;
        me=this_player();
        if(arg != "�ᦷ") 
         return 0;
        else {
        message_vision(
        HIB"$N�ۤF�U��, �Q�K�U�@�������W���ᦷ, �����M��F�ӪšI
$N�����Ӭ�, �o�~�o�{�o�����E���@�حY���Y�{���Pı, �ݨӾ����E
���O�]�k�c�����۹��I�I�I\n"NOR,me);
        return 1;
             }
}
int typepull(string arg)
{
        object me;
        me=this_player();
        if(arg != "�j��") 
         return 0;
        else {
        message_vision(
        HIC "$N���F���, ��n�ϫl�Զ}, ��ı�@�ѤO�q�b�I�W�@��, ���l�w�˪ŦӰ_�I�I\n\n" NOR ,me);
        message_vision( HIC "$N�b�Ť����ѦۥD��½�F�Ӹ��, �V�L�F�j��, �@���Ѷ^�b�a�W, �L���n���k�h...><\n\n" NOR ,me);
        me->move(__DIR__"dst1");
        return 1;
             }
}

