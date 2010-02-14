require 'rake'

OBJ = Dir.glob('bshoes/*.c').collect{|file| file.sub '.c', '.o'}
IDIRS = '-I. -Ideps/ruby/include/ruby-1.9.1 -Ideps/ruby/include/ruby-1.9.1/i386-mingw32'

task :default => 'dist/bshoes.exe'

task 'dist/bshoes.exe' => ['dist/libbshoes.dll', 'bin/main.o'] do |t|
  sh "gcc -o #{t.name} bin/main.o -Ldist -lbshoes -mwindows"
end

task "dist/libbshoes.dll" => OBJ do |t|
  rm_rf 'dist'
  mkdir_p 'dist/ruby'
  cp_r 'deps/ruby/lib/ruby/1.9.1', 'dist/ruby/lib'
  cp 'deps/ruby/bin/msvcrt-ruby191.dll', 'dist'
  cp_r 'lib', 'dist/lib'
  sh "gcc -shared -o #{t.name} #{OBJ.join ' '} -Ldeps/ruby/lib -lmsvcrt-ruby191.dll"
end

rule ".o" => ".c" do |t|
  sh "gcc #{IDIRS} -c -o #{t.name} #{t.source}"
end
