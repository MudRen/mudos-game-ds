#include <ansi.h>
inherit ROOM;
void create()
{
        set("short","�����j�D");
        set("long",@LONG
�۱q�ĺ��Ĵ������P�F��j�����q����f��A�o�̤]�P�˦����H���B
�N�F��Ӱӫ~�o�e���L�a�誺���ߡC�p���@�ӡA���Ӻ����W�Ҫ���f�]
�N���ŨϥΤF�A�b�ӤH�ۦ檺�E��U�A�ĺ��Ĵ���C�C�������@�ӥ�����
�Ӵ�A�o�������j�D�N�O�������H�x�C
LONG 
);
        set("exits",([
            "west":__DIR__"port_05",
            "east":__DIR__"port_11",
            "north":__DIR__"port_07",
            //"south":__DIR__"port_15",
                ]));
        set("objects",([
            __DIR__"npc/business_wm":1,
            __DIR__"npc/business_mn":1,
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

