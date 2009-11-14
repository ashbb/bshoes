require 'rake'

task :default => [:build]
task :build => ["dist/bshoes.exe"]

MSVC_LIBS = 'user32.lib'
MSVC_CFLAGS = " /I#{ENV['SDK_INC_PATH']}"
MSVC_CFLAGS << " /I#{ENV['CRT_INC_PATH']}"
MSVC_LDFLAGS = "/NOLOGO"
MSVC_LDFLAGS << " /LIBPATH:#{ENV['SDK_LIB_PATH'][0..-2]}\i386"
MSVC_LDFLAGS << " /LIBPATH:#{ENV['CRT_LIB_PATH'][0..-2]}\i386"


task "dist/bshoes.exe" => ["bin/main.obj"] do |t|
  mkdir_p "dist"
  rm_f t.name
  sh "link #{MSVC_LDFLAGS} /OUT:#{t.name} /LIBPATH:dist " +
    "/SUBSYSTEM:WINDOWS bin/main.obj #{MSVC_LIBS}"
end

rule ".obj" => ".c" do |t|
  sh "cl /c /nologo /TP /Fo#{t.name} #{MSVC_CFLAGS} #{t.source}"
end
