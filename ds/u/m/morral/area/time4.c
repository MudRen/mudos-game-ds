#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
set("short",HIC"�ɪž�����---A.D 2020"NOR);
set("long",@LONG
�b�Գ��W�A�l�u�p�B���L�A������A�A���B�b���n�b�q������
���������C�A�ݨ�F�H�����`�A�Ө��B�w�����a�A������סA�X�ϧO
�H���L�̦Ӧ����F�ȡA���wí���H���B�ŬX�m�Ӽ֡I�ݬݨ��ǯB�{�b
���䪺�r(look word)�i�H��F�ѫe�]��G�C
LONG);
set("item_desc", ([
"word":@NOTE

�ϡE�� ���������~ í�w�����H

�b�g�١A�x�ƤO�q���ʾ�X��A���ߧ��Ӫ��D�nĳ�D��O���͡A
�p�ѨM�ȯ���D�A�`�|�A������ڽĬ𵥡C

�b��ᢳ���l�~���A�@��í�w���b�B��A��í�������C

���O�A�ĤG�@�ɪ��Ϊv���ťH�g���J�󪱧˥@�ɪ��v�O�A��ꤺ�p
�ĤT�@�ɯ몺�h�W�A�������Ӥ����C
�Ӥ@��ĤT�@�ɰ�a��G�A�ѩ�D�v�L�k�o���A���M�i�H�N�H�f��
��b���������k���W���A�]�S���ȯ���͡A���O�@���H�Ӫ��h�a�v
�h�A�q�p�X�꨺�̱o�쪺�귽�]�֡A�I�U�F�ȡA�D�A�n���a�Ϫ��Ĭ�
�ڷ��C
���O�o�Ǫ�ܲĤT�@�ɤw�g���Ū��ԨơA�b��ɪ��p�X�겴�̡A�u
�O�@�Ǥ���Mí�w�ô����۳¤p�ơC�p�X��S���n���ѻP�o�ǾԨ�
�����G�A�ϱo��ɤw�g�_�����~���]�Φ��F�Ӧۧڥ]�˪����|�C
�~���]�οn���b��ڤW���o�Ǧa�誺�H���V�p�X��ЩR�A���b�p��
�U�������c��x�����o�ǰ�a�C
�̫��p�X��ש�X��ѨM�F�@�ǾԶáA�Ӻ~���]�Τ]�b�H�̪�����
�h�[�W�F�@�D�����C
�o���p�X���٬O����ۥ��y��������A�n�٥u�n���y�����_���A�N�|
��ĤT�@�ɪ���t�g�ٳs�a�_���A�p���p�X��N�O�ҳo�ǰ�a�i�H�[
�J���y�����A�ϥ@�ɴ³�@�g����t�ڶi�C

NOTE
 ]) );
set("exits",([
"north":__DIR__"time5",
"south":__DIR__"time3",
]));
set("light",1);
setup();
replace_program(ROOM);
}

