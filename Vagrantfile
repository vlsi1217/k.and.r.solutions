Vagrant::Config.run do |config|
  config.vm.box = "lucid32"
  config.vm.box_url = "http://mathie-vagrant-boxes.s3.amazonaws.com/debian_squeeze_32.box"

  Vagrant::Config.run do |config|
    config.vm.provision :shell, :path => "Vagrant.sh"
  end
end

