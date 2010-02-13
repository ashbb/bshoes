require 'rake'

task :default => "dist/bshoes.exe"

task "dist/bshoes.exe" => "bin/main.o" do |t|
  rm_rf 'dist'
  mkdir_p 'dist'
  sh "gcc -o #{t.name} bin/main.o -mwindows"
end

rule ".o" => ".c" do |t|
  sh "gcc -c -o #{t.name} #{t.source}"
end
