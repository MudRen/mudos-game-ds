#include <room.h>
inherit ROOM;
void create()
{
        set("short", "�f���B");
        set("long", @LONG
�ݵ۳o�̨Өө������H�s�A����ŵL�@�H������²���O���ۤ��[��
�O�A�j�a��W���j�]�p�]���q�ۡA�ݨӬO�n���^�a��˹����A�@��C����
���b�ʫP�j�a���I���}�F�A���n�b�b�o�̪�ê��q�A�j�a���̨̤��˦a��
�F�@�U�o�Ӧa��A���ۤ@���������t�C���K�N�L�̱����F�C
( ����: use ticket �C )
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
]));
        set("light",1);
        set("objects", ([ /* sizeof() == 1 */
]));

        setup();
        replace_program(ROOM);

}


