inherit ROOM;
void create()
{
 set("short","��V��");

 set("long",@LONG
�o�O���Ф����t�d�l���Q���ѡB�����t�ϩM�ХD�q�r���H�P�H��
�гW���H�A����W��۩��Ъ��гW�A��AŪ��̫�@��ɡA��
�M�ݨ��T�Ӧ���⪺�j�r�i�H�̡E���j�A���T�~�F�@���N���A�J
�Ӭݬݥ|�P�A���W�����F�D��M�l���O�A�a�W��񴳴��A�Ů�
�g���ۤ@�Ѧ�{������C
LONG
    );
 set("exits",([ "west": __DIR__"wl",
"north": __DIR__"gw",
 "south": __DIR__"skycenter",
    ]));
        set("no_kill",1);
        set("light",1);

 setup();
        set("stroom",1);
}
int do_kill(string arg)
{
        if( arg == "guard" || arg == "ming guard" )
        {
                tell_object(this_player(),"�A�Q�n���`�ۤv���⨬�H�I\n");
                return 1;
        }
        else return 0;
}

//have �����t���l���O<===board
//�o�O�@�ӥΨӳq�r�O�H���d���O�A��A�n�q�r�L�H�ɡA��post�W
//��M�o����ѱN�|��M�O�_�q�r�C
