#include <ansi.h>
inherit NPC;

void auto_sch();

string *stars = ({
  "�P�k�y",
  "�A���y",
  "�ѿP�y",
  "���N�y",
  "�_�~�y",
  "�Ѿ®y",
  "�զϮy",
  "�s�Үy",
  "���Үy",
  "�J��y",
  "���\\�y",
  "���~�y",
  "��y",
  "�P�Z�y",
  "�b�H���y",
  "�P���y",
  "�H���y",
  "�����y",
  "��W�y",
  "�j���y",
  "�p���y",
  "���ɮy",
  "���F�y",
  "�Z�v�y",
  "�n�îy",
  "�_�îy",
  "����y",
  "�n�Q�r�y",
  "�Q�~�y",
  "�y���y",
  "���Z�y",
  "���b�y",
  "�C���y",
  "���s�y",
  "�p���y",
  "�i���y",
  "���l�y",
  "���l�y",
  "���b�y",
  "�Z�P�y",
  "�����y",
  "���D�y",
  "���D�y",
  "�L�a�w�y",
  "粪�y",
  "��l�y",
  "�Ѩ߮y",
  "�ѯ��y",
  "�p��y",
  "�[�T�y",
  "�ѿ߮y",
  "�ѵ^�y",
  "�s�׮y",
  "��L��y",
  "�Q��y",
  "�a�Ǯy",
  "�x�خy",
  "�n���y",
  "�D�Үy",
  "�y��y",
  "�ճ��y",
  "�����y",
  "�^�P�y",
  "��Įy",
  "ø�[�y",
  "�n���y",
  "�����y",
  "���F�y",
  "ù�L�y",
  "���ˮy",
  "�ɤҮy",
  "��粮y",
  "�޵P�y",
  "���D�y",
  "�������y",
  "�ѽb�y",
  "�H���y",
  "�����y",
  "�滷��y",
  "�n�T���y",
  "�T���y",
  "���Y�y",
  "�j���y",
  "�p���y",
  "��|�y",
  "�Ǥk�y",
  "�����y",
  "���W�y",
});
  

string *stars_eng = ({
  "Andromeda",
  "Antlia",
  "Apus",
  "Aquila",
  "Aquarius",
  "Ara",
  "Aries",
  "Auriga",
  "Bootes",
  "Caelum",
  "Camelopardalis",
  "Capricornus",
  "Carina",
  "Cassiopeia",
  "Centaurus",
  "Cepheus",
  "Cetus",
  "Chamaeleon",
  "Circinus",
  "Canis Major",
  "Canis Minor",
  "Cancer",
  "Columba",
  "Coma Berenices",
  "Corona Australis",
  "Corona Borealis",
  "Crater",
  "Crux",
  "Corvus",
  "Canes Venatici",
  "Cygnus",
  "Delphinus",
  "Dorado",
  "Draco",
  "Equuleus",
  "Eridanus",
  "Fornax",
  "Gemini",
  "Grus",
  "Hercules",
  "Horologium",
  "Hydra",
  "Hydrus",
  "Indus",
  "Lacerta",
  "Leo",
  "Lepus",
  "Libra",
  "Leo Minor",
  "Lupus",
  "Lynx",
  "Lyra",
  "Mensa",
  "Microscopium",
  "Monocers",
  "Musca",
  "Norma",
  "Octans",
  "Ophiuchus",
  "Orion",
  "Pavo",
  "Pegasus",
  "Perseus",
  "Phoenix",
  "Pictor",
  "Piscis Australis",
  "Pisces",
  "Puppis",
  "Pyxis",
  "Reticulum",
  "Sculptor",
  "Scorpius",
  "Scutum",
  "Serpens",
  "Sextans",
  "Sagitta",
  "Sagittarius",
  "Taurus",
  "Telescopium",
  "Triangulum Australe",
  "Triangulum",
  "Tucana",
  "Ursa Major",
  "Ursa Minor",
  "Vela",
  "Virgo",
  "Volans",
  "Vulpecula",
});

string *replace_stars = ({
  "And",
  "Ant",
  "Aps",
  "Aql",
  "Aqr",
  "Ara",
  "Ari",
  "Aur",
  "Boo",
  "Cae",
  "Cam",
  "Cap",
  "Car",
  "Cas",
  "Cen",
  "Cep",
  "Cet",
  "Cha",
  "Cir",
  "CMa",
  "CMi",
  "Cnc",
  "Col",
  "Com",
  "CrA",
  "CrB",
  "Crt",
  "Cru",
  "Crv",
  "CVn",
  "Cyg",
  "Del",
  "Dor",
  "Dra",
  "Equ",
  "Eri",
  "For",
  "Gem",
  "Gru",
  "Her",
  "Hor",
  "Hya",
  "Hyi",
  "Ind",
  "Lac",
  "Leo",
  "Lep",
  "Lib",
  "LMi",
  "Lup",
  "Lyn",
  "Lyr",
  "Men",
  "Mic",
  "Mon",
  "Mus",
  "Nor",
  "Oct",
  "Oph",
  "Ori",
  "Pav",
  "Peg",
  "Per",
  "Phe",
  "Pic",
  "PsA",
  "Psc",
  "Pup",
  "Pyx",
  "Ret",
  "Scl",
  "Sco",
  "Sct",
  "Ser",
  "Sex",
  "Sge",
  "Sgr",
  "Tau",
  "Tel",
  "TrA",
  "Tri",
  "Tuc",
  "UMa",
  "UMi",
  "Vel",
  "Vir",
  "Vol",
  "Vul",
});

string *chinese_stars = ({
  "�f�D�B�Ѵ\�B�z�J�B���J�B�x�n���B�Ѥj�N�x",
  "�A���B�b�i�J�n",
  "�����B��n��",
  "�ѥ��B�k�X�B���X�B�e���B��վ�B���]�B���]����",
  "�k�J�B��J�B���S���B�M�J�B�q�R�B�\�ΡB�X�ӡB���B�_�B���B�S�z�}�B�ЪL�x�B�y����",
  "�S�B�t",
  "���J�B����B�G�J�B�ѳ�",
  "�����B�W�B���C�B�w���B�K�\�B�y�X",
  "�j���B�k�ᴣ�B���ᴣ�B����B�Үu�B�۷n�B��e�B�C���B�Ѻj�B����",
  "��Ѷ�",
  "���L�k���B����",
});

void create()
{
        int x = random(sizeof(stars));
        set_name(HIW" �P�y "NOR + HIR"[ " + stars[x] + " ] "NOR, ({ "Star: " + stars_eng[x], "stars", "star", stars_eng[x] }));
        set("long", "�o�O�@�s" + stars[x] + "���p�s�P�� ( �A�i�H�� list_stars �Ӭݥثe�Ҧ����P�y )�C\n");

        set("race", "�����H");

        set("chat_chance", 20);
  
        set("level", 100);

        set("unit", "��");
        set("no_fight", 1);
        set("value", 1);

        set("schedule", ([
  "00" : (: auto_sch :),
  "12" : (: auto_sch :),
]));

        setup();
}

void init()
{
        if( this_player() == environment(this_object()) )
                this_object()->move(environment(this_player()));
        if( this_player()->query("id") == "cominging" )
                call_out("meet", 2, this_player());
        add_action("do_list_stars", "list_stars");
}

void die()
{
        return;
}

int talk_action(object me)
{
        command("sigh");
        command("say �n�L�`.. �ڷR�o, �o���R��, ��.... ");
        command("cry " + me->query("id") );
        return 1;
}

void auto_sch()
{
        object new_stars = new(__FILE__);
        message_vision(HIB"$N�t�H����ܥX�G ��... �ڷR�p, �ڿ˷R���p, ���O, �ڥû�����M�p�b�@�_.... \n"NOR, this_object());
        message_vision(HIB"$N���I�Ǥߪ��ˤl, ���]�\, �H, �n�a�t����.... ��\n"NOR, this_object());
        message_vision(HIB"���b���~�����H�`, �ڹL���n�h�W, �n�d��, ��ۦۤv�h�h����, �û�.. �û�.. ��\n"NOR, this_object());
        message_vision(HIR"$N�b�o����, �K���X�F�@������M, �{�{�o�G.. \n"NOR, this_object());
        message_vision(HIC"�u��$N�����b�o�ӥ@�ɤ�, ���G��F�t�@�ӥ@��... \n"NOR, this_object());
        new_stars->move(environment(this_object()));
        destruct(this_object());
}

int do_list_stars(string arg)
{
        object me = this_player();
        string msg = "\n\n  ���X�x�N���x�@�@�ǡ@�@�W�@�@�x Ķ  �W �x����j�N����O��\n" +
		     "�w�w�w�q�w�w�q�w�w�w�w�w�w�w�w�q�w�w�w�w�q�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n",
               chn;
        int i;

        for(i=0;i<sizeof(stars);i++)
        {
                if( i > (sizeof(chinese_stars)-1) )
			msg += sprintf("   %-3d�x%4s�x%16s�x%8s�x\n", i+1, replace_stars[i], stars_eng[i], stars[i]);
                if( i <= (sizeof(chinese_stars)-1) )
			msg += sprintf("   %-3d�x%4s�x%16s�x%8s�x%s \n", i+1, replace_stars[i], stars_eng[i], stars[i], chinese_stars[i]);
                msg+= "�w�w�w�q�w�w�q�w�w�w�w�w�w�w�w�q�w�w�w�w�q�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n";
        }
        msg += "�w�w�w�r�w�w�r�w�w�w�w�w�w�w�w�r�w�w�w�w�r�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n\n";
        me->start_more(msg);
        return 1;
}

void meet(object me)
{
        command("say Johnny, �A�ӤF�r... ");
        command("jump cominging");
        tell_object(me, HIC" - �A�L���n�� ? \n"NOR);
        me->set_temp("spell/bless", 100);
}
