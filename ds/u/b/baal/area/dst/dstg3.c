#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", MAG"�t���w��x�|"NOR);
        set("long", @LONG
���`�۾Q�����p�|�������q�V���誺����, ���Ǫ����
��������Z���F, �䤤���~�ا�O�d�_�ʩ�, ���Y�Ϧb��
�B���ӫ����]���o�@�����O�ô��}��, �������F��S�����~
�ءG"��Ĭ������", �M�b�����s�ߤ~�����Ħ����踪�C
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
            "north": __DIR__"dstg2",
                        "south": __DIR__"dstg1",
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


