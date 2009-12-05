require 'rake'
require 'fileutils'
include FileUtils

def copy_files glob, dir
  FileList[glob].each { |f| cp_r f, dir }
end

task :default => [:build]
task :build => ["dist/bshoes.exe"] do
  mkdir_p "dist/ruby"
  cp_r  "deps/ruby/lib/ruby/1.9.1", "dist/ruby/lib"
end

mkdir_p "dist"
copy_files "deps/ruby/bin/*", "dist/"
cp_r  "lib", "dist/lib"

SRC = FileList["bshoes/*.c"]
OBJ = SRC.map{|x| x.gsub(/\.c$/, '.obj')}

MSVC_LIBS = 'msvcrt-ruby191.lib user32.lib'
MSVC_LIBS2 = ' bufferoverflowu.lib'
MSVC_LIBS << MSVC_LIBS2

MSVC_CFLAGS = %[/MT /DWIN32_LEAN_AND_MEAN
  /Ideps\\ruby\\lib\\ruby\\1.9.1\\i386-mswin32
  /Ideps\\ruby\\include\\ruby-1.9.1
  /Ideps\\ruby\\include\\ruby-1.9.1\\i386-mswin32
  /I.
].gsub(/\n\s*/, ' ')
MSVC_CFLAGS << " /I#{ENV['SDK_INC_PATH']}"
MSVC_CFLAGS << " /I#{ENV['CRT_INC_PATH']}"

MSVC_LDFLAGS = "/NOLOGO"
MSVC_LDFLAGS << " /LIBPATH:#{ENV['SDK_LIB_PATH'][0..-2]}\i386"
MSVC_LDFLAGS << " /LIBPATH:#{ENV['CRT_LIB_PATH'][0..-2]}\i386"


task "dist/bshoes.exe" => ["dist/libbshoes.dll", "bin/main.obj"] do |t|
  rm_f t.name
  sh "link #{MSVC_LDFLAGS} /OUT:#{t.name} /LIBPATH:dist " +
    "/SUBSYSTEM:WINDOWS bin/main.obj libbshoes.lib #{MSVC_LIBS2}"
end

task "dist/libbshoes.dll" => OBJ do |t|
  sh "link #{MSVC_LDFLAGS} /OUT:#{t.name} /dll " +
    "/LIBPATH:deps/ruby/lib " + 
    "#{OBJ.join(' ')} #{MSVC_LIBS}"
end

rule ".obj" => ".c" do |t|
  sh "cl /c /nologo /TP /Fo#{t.name} #{MSVC_CFLAGS} #{t.source}"
end

SRC.zip(OBJ).each do |c, o|
  file o => [c] + Dir["bshoes/*.h"]
end
