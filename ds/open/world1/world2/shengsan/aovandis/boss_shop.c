// �x�~�����󪺭ܮw

inherit ROOM;

void create()
{
	seteuid(getuid(this_object()));
	set("short","�x�~�����󪺭ܮw");
	set("long",@LONG
                 [1;33m�_ �_ �_                    �_ �_ �w��[m
                   [1;33m�~ �]�~ ' �^                �] ' ���^  ��[m
                   [1;33m��==)�^[31mp[33m�]    [37m�@�����H�צ�  [33m �^���]�^�^�x[m
                   [1;31m��  [33m�] [37m�x[33m �^      [37m����         �x[33m �^����[m
                  [1;33m�] �^([37m�s��[33m(    [31m���i�����i��     [37m���s[33m)�][m
                   [1;33m(�^[37m|�_\  [32m*.[31m@[32m. [31m�i�i�i�i�i�i [32m.[31m@[32m.*  [37m/�_|[m
                [1;31m��[33m(�^[37m�]   �^[32m.[31m@�I[32m.[31m���i�i�i�i��[32m.[31m�I@[32m.[37m�]   �^[m
              [1;33m�]�~��[31m��[37m�^ ��-[35m��[31m@[32m.'' [31m���i�i�� [32m''.[31m@[35m��[37m��  �][m
                [1;33m��  [37m��    �s[35m��[32m'.     [31m����     [32m.'[35m��[37m-�s  �@[m
                  [1;37m��      �x                       �x �x            [30m[m
LONG
	);

	set("exits", ([	//�X�f�]��NPC��m,�i�H���]
		"out":	__DIR__"room074",
	]));

	set("light",1);
	set("no_clean_up",1);
	set("objects",([
		"/u/l/luky/npc/item/bag":1,
		"/u/l/luky/npc/eq/blackjacket":3,
		"/u/l/luky/npc/wp/kaisan_b":1,
	]));

	setup();

}