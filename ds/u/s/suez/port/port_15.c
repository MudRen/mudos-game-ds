#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�X�Y�s��");
        set("long",@LONG
�o�̬O�ĺ��Ĵ��X�Y�s���A�Ҧ����f�����B�e��o�̦A�����W�A��
�ܦ��@�Ӹرi�����k�u�b�ĺ��Ĵ��X�Y�s���A�A�i�H���@�ɤW�Ҧ����F
��A�]�A�A���T�Q�~�e�諸���ǡC�v�o�]�O�ب�ӤH�u�n�������򳣽檺
���ܡA���L�o�̦��۪F���j�������ȿ��ӫ~�ˬO�����C
LONG 
);
        set("exits",([
            "east":__DIR__"port_19",
            "north":__DIR__"port_08",
            "south":__DIR__"port_18",
                ]));
        set("objects",([
             __DIR__"npc/waterman":3,
                ]));

        set("world","world1");
        set("outdoor","land");

        setup();

}
int room_effect(object me)
{
        switch(random(14))
        {
                
         case 7:        message_vision("�@���f����a��F�A�u����f�W�@���V�áC\n",me);
                        return 1;
         case 6:        message_vision("������㻷���W�ǨӤF�C�I�������n�C\n",me);
                        return 1;
         case 5:
         case 4:        message_vision("����̰۵ۡR�u�L�����B����o�I�h�⤰����v\n",me);
                        return 1;
         
         case 3:
         case 2:        message_vision("����̦[�ܵۡR�u�ӳ�I�ӳ�I�n�I�A�L�Ӥ@�I�I�v\n",me);
                        return 1;
         case 1:
         case 0:        message_vision("�a���Ш��������I�I���j�ۡ��C\n",me);
                        return 1;
         
         default:       return 1;
        }
}


