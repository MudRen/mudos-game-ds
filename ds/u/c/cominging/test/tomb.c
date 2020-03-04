//
// �ھکұ����쪺�Ѯ�T��, �ӧ��ܩж����ԭz
//
//                                              Created by Caesar

#include <mudlib.h>

inherit MONSTER;

#define ROOM_DIR "/u/c/caesar/home/"                    // ��ж����ؿ�

string status;
string query_weather_status() { return status; }        // ���s���J���ж���
                                                        // �D�{�b�O�դѩαߤW

int clean_up() { return 0; }                            // ���L���Q�M��

// �ھڤѮ�, �ӧP�_�դѩαߤW, �i��|���I���D, ���L���ӨS���a
void init_weather_status()
{
        switch( "/adm/daemons/weather_d"->query_current_day_phase() )
        {
                case "�Ӷ������~�}�l�X�{�b�F�誺�a���u�W�C\n" :
                case "�Ӷ����X�{�b�F�誺�a���u�W�M�{�b�O�M��\n" :
                case "�Ӷ��q�F�誺�a���u�W�@�_�F�C\n" :
                case "�Ӷ��������b�F�誺�ѪŤ�\n" :
                case "�Ӷ��w�g�@��ѪŪ��������C\n" :
                case "�Ӷ��q�A�����W���ģ�ۤj�a\n" :
                case "�Ӷ��}�l�V�貾�ʡC\n" :
                case "�Ӷ��������b���䪺�ѪŤ�\n" :
                case "�Ӷ��}�l�S�J��誺�a���u�C\n" :
                case "�i�����l����ģ�ۦ�誺����\n" :
                case "�̫�@�u�i�������~�]�����b�a���u�W�C\n" :
                case "���䪺�ѪŤ��ݯd�۩��t���i���l��\n" :
                        status = "�դ�";        
                        break;
                default :
                        status = "�ߤW";
                        break;
        }
}

void create()
{
        ::create();
        seteuid(getuid());
        set_level(19);
        set_name( "Weather Controled Daemon", "�Q�Ѯ𱱨�t��" );
        set_short( "�Q�Ѯ𱱨�t��" );
        set_long( "�Q�Ѯ𱱨�t��\n" );
        set_living_name( "Controled" );
        add( "id", ({ "controled", "daemon" }) );
        set( "gender", "neuter" );
        set( "unit", "�x" );

        // �[�J�����Ѯ��ܤƪ���C
        "/adm/daemons/weather_d"->request_weather_notices(this_object());
        
        // �����{�b�����p, �O�դѩαߤW
        init_weather_status();
}

// ���w���J�ж����ԭz
void change_room_long()
{
        object room;
        string *rooms, room_file;
        int    i;

        rooms = get_dir( ROOM_DIR );
        i = sizeof(rooms);

        while(i--)
        {
                room_file = ROOM_DIR + rooms[i];

                if( file_size( room_file ) == -2 )      // �ؿ�
                        continue;
                if( !room = find_object( room_file ) )  // �|�����J��, �N���ޥL
                        continue;
                room->change_long(status);
        }
}

// ��g relay_message ���L��Ѯ��ܤƦ��ʧ@                
void relay_message(string cla, string msg)
{
        switch(msg)
        {
                case "�Ӷ������~�}�l�X�{�b�F�誺�a���u�W�C\n" :
                        status = "�դ�";
                        change_room_long();
                        return;

                case "�Ѫŧ����t�U�ӡM�]�߭��{�F�C\n" :
                        status = "�ߤW";
                        change_room_long();
                        return;

                default :
                        return;
        }
}
